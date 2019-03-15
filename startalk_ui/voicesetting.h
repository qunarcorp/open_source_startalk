#ifndef VOICESETTING_H
#define VOICESETTING_H

#include "LocalManDialog.h"
#include "UtilHelper.h"

namespace Ui
{
	class VoiceSetting;
}

class VoiceSetting : public LocalManDialog
{
	Q_OBJECT
friend class Util::SingletonTemplete<VoiceSetting> ; 
public:
private:
	VoiceSetting(QWidget *parent=NULL);
	~VoiceSetting();
private:
	void InitLineEdit();
	void InitConnect();


private:
	Ui::VoiceSetting *ui;
};
typedef Util::SingletonTemplete<VoiceSetting>  VoiceSettingsingleton;
#endif // VOICESETTING_H
