#include "MessageNoneBubbleWrapper.h"
#include "XmppMessage.h"
#include "wrapper/MessageDecoraterFrameOther.h"
#include "wrapper/MessageDecoraterFrameSelf.h"
#include "wrapper/MessageDecoraterSkeletonGOther.h"
#include "wrapper/MessageDecoraterSkeletonSOhter.h"
#include "wrapper/MessageDecoraterSkeletonSelf.h"
#include "wrapper/MessageDecoraterBubbleWrapperOther.h"
#include "wrapper/MessageDecoraterBubbleWrapperSelf.h"

MessageNoneBubbleWrapper::MessageNoneBubbleWrapper(QSharedPointer<IMessageBubble> bubble)
	: MessageDecoraterBase(bubble)
{
	spGroupOtherBubble = MessageDecoraterFrameOther::decorate(MessageDecoraterSkeletonGOther::decorate(bubble));
	spSimpleOtherBubble = MessageDecoraterFrameOther::decorate(MessageDecoraterSkeletonSOhter::decorate(bubble));
	spSimpleSelfBubble =  MessageDecoraterFrameSelf::decorate(MessageDecoraterSkeletonSelf::decorate(bubble));
}



MessageNoneBubbleWrapper::~MessageNoneBubbleWrapper()
{

}

int MessageNoneBubbleWrapper::getMessageMediaType()
{
	return spGroupOtherBubble->getMessageMediaType();// 随便取一个
}

bool MessageNoneBubbleWrapper::getTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& htmlString)
{
	if (!spMessage.isNull())
	{
		if ( Biz::GroupMessage == spMessage->MsgSourceType())
		{
			if (Biz::MessageTypeOther == spMessage->MsgDirection() )
			{
				if (!spGroupOtherBubble.isNull())
				{
					return spGroupOtherBubble->getTranslatedMessage(spMessage,htmlString);
				}
			}
			else
			{
				if (!spSimpleSelfBubble.isNull())
				{
					return spSimpleSelfBubble->getTranslatedMessage(spMessage,htmlString);
				}
			}
		}
		else
		{
			if (Biz::MessageTypeOther == spMessage->MsgDirection() )
			{
				if (!spSimpleOtherBubble.isNull())
				{
					return spSimpleOtherBubble->getTranslatedMessage(spMessage,htmlString);
				}
			}
			else
			{
				if (!spSimpleSelfBubble.isNull())
				{
					return spSimpleSelfBubble->getTranslatedMessage(spMessage,htmlString);
				}
			}

		}
	}
	return false;
}

bool MessageNoneBubbleWrapper::getShotTranslatedMessage(QSharedPointer<Biz::XmppMessage> spMessage,QString& body)
{
	if (spMessage.isNull())
	{
		return false;
	}
	if ( Biz::GroupMessage == spMessage->MsgSourceType())
	{
		if (Biz::MessageTypeSelf == spMessage->MsgDirection() )
		{
			if (!spGroupOtherBubble.isNull())
			{
				return spGroupOtherBubble->getShotTranslatedMessage(spMessage,body);
			}
		}
		else
		{
			if (!spSimpleSelfBubble.isNull())
			{
				return spSimpleSelfBubble->getShotTranslatedMessage(spMessage,body);
			}
		}
	}
	else
	{
		if (Biz::MessageTypeSelf == spMessage->MsgDirection() )
		{
			if (!spSimpleOtherBubble.isNull())
			{
				return spSimpleOtherBubble->getShotTranslatedMessage(spMessage,body);
			}
		}
		else
		{
			if (!spSimpleSelfBubble.isNull())
			{
				return spSimpleSelfBubble->getShotTranslatedMessage(spMessage,body);
			}
		}

	}
	return false;
}

