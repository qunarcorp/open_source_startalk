
#ifdef __cplusplus
extern "C" {
#endif

#ifndef AMRNB_WRAPPER_INTERNAL
    /* Copied from enc/src/gsmamr_enc.h */
    enum Mode {
        MR475 = 0,/* 4.75 kbps */
        MR515,    /* 5.15 kbps */
        MR59,     /* 5.90 kbps */
        MR67,     /* 6.70 kbps */
        MR74,     /* 7.40 kbps */
        MR795,    /* 7.95 kbps */
        MR102,    /* 10.2 kbps */
        MR122,    /* 12.2 kbps */
        MRDTX,    /* DTX       */
        N_MODES   /* Not Used  */
    };
#endif

    void* Decoder_Interface_init(void);
    void Decoder_Interface_exit(void* state);
    void Decoder_Interface_Decode(void* state, const unsigned char* in, short* out, int bfi);

    void* Encoder_Interface_init(int dtx);
    int Encoder_Interface_Encode(void* s, enum Mode mode, const short* speech, unsigned char* out, int forceSpeech);
    void Encoder_Interface_exit(void* s);
#ifdef __cplusplus
}
#endif