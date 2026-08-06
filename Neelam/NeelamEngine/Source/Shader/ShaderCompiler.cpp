//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderCompiler.h"

// COM release helper (DXC objects are COM). Releases and nulls the pointer;
// safe to call on a null or already-released pointer.
#ifndef SafeRelease
#define SafeRelease(x) { if(x){ x->Release(); x = 0; } }
#endif

namespace Neelam::vk
{
	// HLSL target profile per stage. Shader Model 6.0 is the DXC baseline.
	static const wchar_t *privProfile(ShaderStage stage)
	{
		switch (stage)
		{
		case ShaderStage::Vertex: return L"vs_6_0";
		case ShaderStage::Pixel:  return L"ps_6_0";
		default:                  return L"";
		}
	}

	IDxcBlob *ShaderCompiler::CompileFile(const char *pFilePath, ShaderStage stage)
	{
		// DXC wants wide-char paths/args. Paths here are plain ASCII.
		wchar_t wPath[512] = {};
		MultiByteToWideChar(CP_UTF8, 0, pFilePath, -1, wPath, 512);

		// DXC entry points. Created per call -> no shared state across threads.
		IDxcUtils     *pUtils    = nullptr;
		IDxcCompiler3 *pCompiler = nullptr;
		DxcCreateInstance(CLSID_DxcUtils, IID_PPV_ARGS(&pUtils));
		DxcCreateInstance(CLSID_DxcCompiler, IID_PPV_ARGS(&pCompiler));

		if (pUtils == nullptr || pCompiler == nullptr)
		{
			Debug::out("ShaderCompiler: DxcCreateInstance failed\n");
			SafeRelease(pCompiler);
			SafeRelease(pUtils);
			return nullptr;
		}

		// Read the .hlsl source off disk (every call -> picks up edits).
		IDxcBlobEncoding *pSource = nullptr;
		HRESULT hr = pUtils->LoadFile(wPath, nullptr, &pSource);
		if (FAILED(hr) || pSource == nullptr)
		{
			Debug::out("ShaderCompiler: could not read '%s'\n", pFilePath);
			SafeRelease(pSource);
			SafeRelease(pCompiler);
			SafeRelease(pUtils);
			return nullptr;
		}

		DxcBuffer source = {};
		source.Ptr      = pSource->GetBufferPointer();
		source.Size     = pSource->GetBufferSize();
		source.Encoding = DXC_CP_ACP;

		const wchar_t *args[] =
		{
			L"-E", L"main",					// entry point
			L"-T", privProfile(stage),		// target profile (vs_6_0 / ps_6_0)
			L"-spirv",						// emit SPIR-V, not DXIL
			L"-fspv-target-env=vulkan1.3"	// SPIR-V 1.6, fine for our 1.4 instance
		};

		IDxcResult *pResult = nullptr;
		hr = pCompiler->Compile(&source, args, (UINT32)_countof(args), nullptr, IID_PPV_ARGS(&pResult));

		SafeRelease(pSource);

		if (FAILED(hr) || pResult == nullptr)
		{
			Debug::out("ShaderCompiler: DXC Compile() failed for '%s'\n", pFilePath);
			SafeRelease(pResult);
			SafeRelease(pCompiler);
			SafeRelease(pUtils);
			return nullptr;
		}

		// Diagnostics: print warnings/errors (this is what you read after a bad
		// edit while hot-reloading).
		IDxcBlobUtf8 *pErrors = nullptr;
		pResult->GetOutput(DXC_OUT_ERRORS, IID_PPV_ARGS(&pErrors), nullptr);
		if (pErrors != nullptr && pErrors->GetStringLength() > 0)
		{
			Debug::out("ShaderCompiler [%s]:\n%s\n", pFilePath, pErrors->GetStringPointer());
		}
		SafeRelease(pErrors);

		HRESULT status = S_OK;
		pResult->GetStatus(&status);
		if (FAILED(status))
		{
			Debug::out("ShaderCompiler: compile FAILED for '%s'\n", pFilePath);
			SafeRelease(pResult);
			SafeRelease(pCompiler);
			SafeRelease(pUtils);
			return nullptr;
		}

		// The SPIR-V object blob.
		IDxcBlob *pSpirv = nullptr;
		pResult->GetOutput(DXC_OUT_OBJECT, IID_PPV_ARGS(&pSpirv), nullptr);

		SafeRelease(pResult);
		SafeRelease(pCompiler);
		SafeRelease(pUtils);

		if (pSpirv == nullptr || pSpirv->GetBufferSize() == 0)
		{
			Debug::out("ShaderCompiler: no SPIR-V produced for '%s'\n", pFilePath);
			SafeRelease(pSpirv);
			return nullptr;
		}

		return pSpirv;
	}
}

// ---  End of File ---
