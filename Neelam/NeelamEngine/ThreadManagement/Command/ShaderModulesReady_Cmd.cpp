//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderModulesReady_Cmd.h"
#include "ShaderObjectNodeMan.h"

namespace Neelam
{
	ShaderModulesReady_Cmd::ShaderModulesReady_Cmd(vk::ShaderObject::Name name,
												   IDxcBlob *pVertexSpirv,
												   IDxcBlob *pPixelSpirv)
		: Command(),
		  privName(name),
		  poVertexSpirv(pVertexSpirv),
		  poPixelSpirv(pPixelSpirv)
	{
	}

	//-----------------------------------------------------------------
	// Blob release lives in the DESTRUCTOR, not Execute(). That way it happens
	// on every path -- including the one where QueueMan::Destroy deletes this
	// command at shutdown without ever executing it. Putting it in Execute()
	// would leak the SPIR-V on exactly that path.
	//-----------------------------------------------------------------
	ShaderModulesReady_Cmd::~ShaderModulesReady_Cmd()
	{
		// (ShaderCompiler.cpp has a SafeRelease macro, but it is file-local.)
		if (this->poVertexSpirv != nullptr)
		{
			this->poVertexSpirv->Release();
			this->poVertexSpirv = nullptr;
		}
		if (this->poPixelSpirv != nullptr)
		{
			this->poPixelSpirv->Release();
			this->poPixelSpirv = nullptr;
		}
	}

	void ShaderModulesReady_Cmd::Execute()
	{
		// Engine thread. Resolve by NAME -- the technique may be gone.
		vk::ShaderObject *pShader = vk::ShaderObjectNodeMan::Find(this->privName);

		if (pShader != nullptr)
		{
			pShader->ReloadFromBlobs(this->poVertexSpirv, this->poPixelSpirv);
		}
		else
		{
			// Not an error: the technique was destroyed while the compile was
			// in flight. Exactly the case a raw pointer would have crashed on.
			Debug::out("ShaderModulesReady: technique gone, reload dropped\n");
		}

		delete this;		// consumer owns the command; ~dtor releases the blobs
	}
}

// ---  End of File ---
