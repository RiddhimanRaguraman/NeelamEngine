//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_MODULES_READY_CMD_H
#define SHADER_MODULES_READY_CMD_H

#include "Command.h"
#include "ShaderObject.h"

namespace Neelam
{
	//-----------------------------------------------------------------------
	// class ShaderModulesReady_Cmd
	//
	// "SPIR-V is compiled -- swap it in." Posted by the FileThread, executed on
	// the ENGINE thread, which is the only place vkCreateShaderModule and the
	// pipeline rebuild may happen.
	//
	// Carries a ShaderObject::NAME, never a pointer: the technique could have
	// been destroyed while the compile was in flight. Execute() resolves it via
	// ShaderObjectNodeMan::Find(), and a nullptr result simply means "gone" --
	// the blobs are released and nothing else happens.
	//
	// OWNS the two blobs. Whatever path it takes, it releases them.
	//-----------------------------------------------------------------------
	class ShaderModulesReady_Cmd final : public Command
	{
	public:
		ShaderModulesReady_Cmd() = delete;
		ShaderModulesReady_Cmd(const ShaderModulesReady_Cmd &) = delete;
		ShaderModulesReady_Cmd &operator = (const ShaderModulesReady_Cmd &) = delete;
		virtual ~ShaderModulesReady_Cmd();

		ShaderModulesReady_Cmd(vk::ShaderObject::Name name,
							   IDxcBlob *pVertexSpirv,
							   IDxcBlob *pPixelSpirv);

		virtual void Execute() override;

	private:
		vk::ShaderObject::Name privName;
		IDxcBlob              *poVertexSpirv;		// owned
		IDxcBlob              *poPixelSpirv;		// owned
	};
}

#endif   // SHADER_MODULES_READY_CMD_H

// ---  End of File ---
