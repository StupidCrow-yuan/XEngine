//
// Created by yuan on 4/10/22.
//

#ifndef XENGINEMAIN_XEPCH_H
#define XENGINEMAIN_XEPCH_H

#include "Xengine/Core/PlatformDetection.h"

#ifdef XE_PLATFORM_WINDOWS
#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Xengine/Core/Base.h"

#include "Xengine/Core/Log.h"

#include "Xengine/Debug/Instrumentor.h"

#ifdef XE_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#endif //XENGINEMAIN_XEPCH_H
