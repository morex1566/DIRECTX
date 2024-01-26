#include "PCH.h"
#include "CTexture.h"
#include "DirectXTex/DirectXTex.h"
#include "SApplication.h"
#include "SConsole.h"

CTexture::CTexture(const OGameObject* InOwner)
	: OComponent(InOwner)
{
}

CTexture::~CTexture()
{
	Release();
}

void CTexture::Initialize()
{
	OComponent::Initialize();
}

void CTexture::Release()
{
	OComponent::Release();

	if (Resource)
	{
		Resource->Release();
		Resource = nullptr;
	}
}

void CTexture::Start()
{
	OComponent::Start();
}

void CTexture::Tick()
{
	OComponent::Tick();
}

void CTexture::End()
{
	OComponent::End();
}

void CTexture::Load(const std::wstring& InFilePath, ETexture InType)
{
	Release();

	HRESULT result;
	DirectX::ScratchImage image;

	auto DirectX11 = SApplication::GetDirectX11();

	switch (InType)
	{
		case ETexture::DDS:
		{
			result = LoadFromDDSFile(InFilePath.c_str(), DirectX::DDS_FLAGS_NONE, nullptr, image);
			if (SUCCEEDED(result))
			{
				result = DirectX::CreateShaderResourceView(&DirectX11->GetDevice(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), &Resource);
				if (FAILED(result))
				{
					SConsole::LogError(L"CreateShaderResourceView() is failed.");
					return;
				}
			}
			else
			{
				SConsole::LogError(L"LoadFromDDSFile() is failed.");
				return;
			}

			break;
		}

		case ETexture::TGA:
		{
			result = LoadFromTGAFile(InFilePath.c_str(), nullptr, image);
			if (SUCCEEDED(result))
			{
				result = DirectX::CreateShaderResourceView(&DirectX11->GetDevice(), image.GetImages(), image.GetImageCount(), image.GetMetadata(), &Resource);
				if (FAILED(result))
				{
					SConsole::LogError(L"CreateShaderResourceView() is failed.");
					return;
				}
			}
			else
			{
				SConsole::LogError(L"LoadFromDDSFile() is failed.");
				return;
			}

			break;
		}
	}
}