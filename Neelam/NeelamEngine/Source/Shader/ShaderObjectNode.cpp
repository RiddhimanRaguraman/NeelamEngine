//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderObjectNode.h"

namespace Neelam::vk
{
	ShaderObjectNode::ShaderObjectNode()
		: Azul::DLink(),
		  poShader(nullptr),
		  privName(ShaderObject::Name::NOT_INITIALIZED)
	{
	}

	ShaderObjectNode::~ShaderObjectNode()
	{
		this->privClear();
	}

	void ShaderObjectNode::Set(ShaderObject *pShader)
	{
		assert(pShader);

		this->poShader = pShader;
		this->privName = pShader->GetName();
	}

	void ShaderObjectNode::SetName(ShaderObject::Name name)
	{
		// Compare-node path: no ShaderObject, just the key.
		this->privName = name;
	}

	ShaderObject *ShaderObjectNode::GetShaderObject()
	{
		return this->poShader;
	}

	void ShaderObjectNode::privClear()
	{
		// BORROWED -- drop, never delete. Game owns the technique.
		this->poShader = nullptr;
		this->privName = ShaderObject::Name::NOT_INITIALIZED;
	}

	// char*, not const char*, to match the Azul::DLink override it implements.
	// Returns string literals, so there is no shared buffer to race on.
	char *ShaderObjectNode::GetName()
	{
		const char *pName = "ShaderObject::<unknown>";

		switch (this->privName)
		{
		case ShaderObject::Name::ColorByVertex:		pName = "ShaderObject::ColorByVertex";		break;
		case ShaderObject::Name::NOT_INITIALIZED:	pName = "ShaderObject::NOT_INITIALIZED";	break;
		case ShaderObject::Name::NullShader:		pName = "ShaderObject::NullShader";			break;
		default:									assert(false);								break;
		}

		return (char *)pName;
	}

	ShaderObject::Name ShaderObjectNode::GetShaderName() const
	{
		return this->privName;
	}

	void ShaderObjectNode::Wash()
	{
		this->privClear();
	}

	void ShaderObjectNode::Dump()
	{
		Debug::out("      ShaderObjectNode(%p)\n", this);
		Debug::out("      ShaderObject(%p)  Name: %s \n", this->poShader, this->GetName());

		Azul::DLink::Dump();
	}
}

// ---  End of File ---
