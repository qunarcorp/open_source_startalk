#include "VoiceHelper.h"
#include "amr/include/wrapper.h"
#include <stdint.h>
#include "wavreader.h"

//#pragma comment(lib,"./amr/lib/opencore-amr-nb-lite.lib") 

const int sizes[] = { 12, 13, 15, 17, 19, 20, 26, 31, 5, 6, 5, 5, 0, 0, 0, 0 };
VoiceHelper::VoiceHelper(void)
{
}


VoiceHelper::~VoiceHelper(void)
{
}

bool VoiceHelper::amrFileToWavBuffer(const char* szAmrFileName, QByteArray& arrWavData)
{
#ifndef Q_NO_AMR
    char header[6];
    int n;
    FILE* in;
    void *amr;
    void *amrDecoder;
    
    in = fopen(szAmrFileName, "rb");	
    if (!in)
        return false;    

    //check the file format
    n = fread(header, 1, 6, in);
    if (n != 6 || memcmp(header, "#!AMR\n", 6)) {
        fprintf(stderr, "Bad header\n");
        return false;
    }    
    amr =Decoder_Interface_init();

    while (1) 
    {

        uint8_t buffer[500], littleendian[320], *ptr;
        int size, i;
        int16_t outbuffer[160];

        //default read frame to buffer
        /* Read the mode byte */
        n = fread(buffer, 1, 1, in);
        if (n <= 0)
            break;

        /* Find the packet size */
        size = sizes[(buffer[0] >> 3) & 0x0f];
        n = fread(buffer + 1, 1, size, in);
        if (n != size)
            break;

        /* Decode the packet */
        Decoder_Interface_Decode(amr, buffer, outbuffer, 0);

        /* Convert to little endian and write to wav */
        ptr = littleendian;
        for (i = 0; i < 160; i++) {
            *ptr++ = (outbuffer[i] >> 0) & 0xff;
            *ptr++ = (outbuffer[i] >> 8) & 0xff;
        }
        arrWavData.append((const char *)littleendian, 320);
    }    

    fclose(in);
    Decoder_Interface_exit(amr);
    return true;
#endif
    return false;
}

bool VoiceHelper::amrBufferToWavBuffer(unsigned char* inBuffer,int inBufferLen, QByteArray& arrWavData)
{
#ifndef Q_NO_AMR
    void *amr;
    void *amrDecoder;
    unsigned char* pBuf = inBuffer;
 
    //check the file format
    if (memcmp(inBuffer, "#!AMR\n", 6)) {
        fprintf(stderr, "Bad header\n");
        return false;
    }else{
        pBuf += 6;
    }        
    amr =Decoder_Interface_init();

    while (1) 
    {

        uint8_t buffer[500], littleendian[320], *ptr;
        int size, i;
        int16_t outbuffer[160];

        //default read frame to buffer
        /* Read the mode byte */
        /*n = fread(buffer, 1, 1, in);
        if (n <= 0)
        break;*/
        if(pBuf <= inBuffer + inBufferLen)
            buffer[0] = (uint8_t)*pBuf++;        
        else
            break;
        
        /* Find the packet size */
        size = sizes[(buffer[0] >> 3) & 0x0f];
        //n = fread(buffer + 1, 1, size, in);
        if( pBuf + size > inBuffer + inBufferLen)        
            break;
        else{
            memcpy(buffer+1,pBuf,size);
            pBuf += size;
        }


        /* Decode the packet */
        Decoder_Interface_Decode(amr, buffer, outbuffer, 0);

        /* Convert to little endian and write to wav */
        ptr = littleendian;
        for (i = 0; i < 160; i++) {
            *ptr++ = (outbuffer[i] >> 0) & 0xff;
            *ptr++ = (outbuffer[i] >> 8) & 0xff;
        }
        arrWavData.append((const char *)littleendian, 320);
    }    
    
    Decoder_Interface_exit(amr);
    return true;
#endif
    return false;
}

bool VoiceHelper::WavBufferToAmrFile(const char* pArrWavData, int wavDatalen,  const char* szAmrFileName)
{   
    return true;
}
bool VoiceHelper::WavFileToAmrFile(const char* szWavFileName,  const char* szAmrFileName)
{
#ifndef Q_NO_AMR
    enum Mode mode = MR122;
    const char *setMode = "12200";
    int ch, dtx = 0;
    int optind=3;
    const char *infile, *outfile;
    FILE *out;
    void *wav;
    
    int format=1;
    int sampleRate=8000;
    int channels= 1;
    int bitsPerSample=16;
    int inputSize;
    uint8_t* inputBuf;
    void* amr;

    fprintf(stderr, "AMR-NB Encode .wav file to .amr\n");

    infile = szWavFileName;
    outfile = szAmrFileName;

    wav = wav_read_open(infile);

    if (!wav) {
        fprintf(stderr, "Unable to open wav file %s\n", infile);
        return false;
    }
    if (!wav_get_header(wav, &format, &channels, &sampleRate, &bitsPerSample, NULL)) {
        fprintf(stderr, "Bad wav file %s\n", infile);
        return false;
    }
    if (format != 1) {
        fprintf(stderr, "Unsupported WAV format %d\n", format);
        return false;
    }
    if (bitsPerSample != 16) {
        fprintf(stderr, "Unsupported WAV sample depth %d\n", bitsPerSample);
        return false;
    }
    if (channels != 1)
        fprintf(stderr, "Warning, only compressing one audio channel\n");
    if (sampleRate != 8000)
        fprintf(stderr, "Warning, AMR-NB uses 8000 Hz sample rate (WAV file has %d Hz)\n", sampleRate);

    inputSize = channels*2*160;
    inputBuf = (uint8_t*) malloc(inputSize);
    amr = Encoder_Interface_init(dtx);

    //amr default
    out = fopen(outfile, "wb");
    if (!out) {
        perror(outfile);
        return false;
    }

    fwrite("#!AMR\n", 1, 6, out);

    while (1) {
        short buf[160];
        uint8_t outbuf[500];
        int read, i, n;

        read = wav_read_data(wav, inputBuf, inputSize);
        read /= channels;
        read /= 2;

        if (read < 160)
            break;
        for (i = 0; i < 160; i++) {
            const uint8_t* in = &inputBuf[2*channels*i];
            buf[i] = in[0] | (in[1] << 8);
        }

        n = Encoder_Interface_Encode(amr, mode, buf, outbuf, 0);
       
        //default
        fwrite(outbuf, 1, n, out);
    }//end while

    free(inputBuf);
    fclose(out);
    Encoder_Interface_exit(amr);
    wav_read_close(wav);

    fprintf(stderr, "Finished Encode\n");
    return true;
#endif
    return false;
}

bool VoiceHelper::WavFileToAmrBuffer(const char* szWavFileName, QByteArray& arrAmrData)
{
#ifndef Q_NO_AMR
    enum Mode mode = MR122;
    const char *setMode = "12200";
    int ch, dtx = 0;
    int optind=3;
    const char *infile;
    //FILE *out;
    void *wav;
    int format=1;
    int sampleRate=8000;
    int channels= 1;
    int bitsPerSample=16;
    int inputSize;
    uint8_t* inputBuf;
    void* amr;

    fprintf(stderr, "AMR-NB Encode .wav file to .amr\n");
    infile = szWavFileName;   
    wav = wav_read_open(infile);

    if (!wav) {
        fprintf(stderr, "Unable to open wav file %s\n", infile);
        return false;
    }
    if (!wav_get_header(wav, &format, &channels, &sampleRate, &bitsPerSample, NULL)) {
        fprintf(stderr, "Bad wav file %s\n", infile);
        return false;
    }
    if (format != 1) {
        fprintf(stderr, "Unsupported WAV format %d\n", format);
        return false;
    }
    if (bitsPerSample != 16) {
        fprintf(stderr, "Unsupported WAV sample depth %d\n", bitsPerSample);
        return false;
    }
    if (channels != 1)
        fprintf(stderr, "Warning, only compressing one audio channel\n");
    if (sampleRate != 8000)
        fprintf(stderr, "Warning, AMR-NB uses 8000 Hz sample rate (WAV file has %d Hz)\n", sampleRate);

    inputSize = channels*2*160;
    inputBuf = (uint8_t*) malloc(inputSize);
    amr = Encoder_Interface_init(dtx);

    //amr default
//     out = fopen(outfile, "wb");
//     if (!out) {
//         perror(outfile);
//         return false;
//     }

    //fwrite("#!AMR\n", 1, 6, out);
    arrAmrData.append("#!AMR\n");

    while (1) {
        short buf[160];
        uint8_t outbuf[500];
        int read, i, n;

        read = wav_read_data(wav, inputBuf, inputSize);
        read /= channels;
        read /= 2;

        if (read < 160)
            break;
        for (i = 0; i < 160; i++) {
            const uint8_t* in = &inputBuf[2*channels*i];
            buf[i] = in[0] | (in[1] << 8);
        }

        n = Encoder_Interface_Encode(amr, mode, buf, outbuf, 0);

        //default
        //fwrite(outbuf, 1, n, out);
        arrAmrData.append((const char *)outbuf, n);
    }//end while

    free(inputBuf);
    //fclose(out);
    Encoder_Interface_exit(amr);
    //close input file
    wav_read_close(wav);

    fprintf(stderr, "Finished Encode\n");
    return true;
#endif
    return false;
}
