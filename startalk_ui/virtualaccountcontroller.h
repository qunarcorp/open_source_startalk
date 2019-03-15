#ifndef VIRTUALACCOUNTCONTROLLER_H
#define VIRTUALACCOUNTCONTROLLER_H

#include "ControllerBase.h"
namespace MainApp
{
	class VirtualAccountController : public ControllerBase
	{
		Q_OBJECT

	public:
		VirtualAccountController();
		~VirtualAccountController();
	public:
		virtual void initController();
		virtual void unInitController();
	
	};
}
#endif // VIRTUALACCOUNTCONTROLLER_H
