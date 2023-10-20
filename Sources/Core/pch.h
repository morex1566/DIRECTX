#pragma once
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#pragma warning(disable: 26495)
#pragma warning(disable: 4267)


#define WIN32_LEAN_AND_MEAN
#define GET_SHADER_FILE_DIR(SHADER_FILE_NAME_) std::string(SHADERS_FOLDER_DIR) + SHADER_FILE_NAME_

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iomanip>
#include <memory>
#include <time.h>
#include <Windows.h>
#include <wrl/client.h>
#include <sstream>
#include <conio.h>
#include <fstream>
#include <codecvt>
#include <locale>
#include <chrono>
#include <wrl/client.h>

#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_dx12.h"

#include "json/json_fwd.hpp"
#include "json/json.hpp"

using namespace DirectX;
using namespace nlohmann;
using namespace Microsoft::WRL;


#include "Type.h"
#include "Console.h"
#include "Utils.h"
#include "Config.h"
#include "Object.h"