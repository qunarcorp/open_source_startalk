#include <QtCore>
#include "Log.h"

namespace Util{}
using namespace Util;
#if _DEBUG
#ifndef MYNEW
#define MYNEW
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)
#endif
#endif