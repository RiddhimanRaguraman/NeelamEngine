//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_OBJECT_NODE_H
#define SHADER_OBJECT_NODE_H

#include "DLink.h"
#include "ShaderObject.h"

namespace Neelam::vk
{
	//-----------------------------------------------------------------------
	// class ShaderObjectNode
	//
	// DLink node wrapping one ShaderObject, so ShaderObjectNodeMan can find a
	// technique by ShaderObject::Name.
	//
	// DIFFERENT FROM CameraNode: the ShaderObject is BORROWED, not owned. A
	// technique is a Game member (Game::triangleShader), not a heap object, so
	// deleting it here would be a double-free at shutdown. Wash()/privClear()
	// therefore only drop the pointer.
	//-----------------------------------------------------------------------
	class ShaderObjectNode : public Azul::DLink
	{
	public:
		ShaderObjectNode();
		ShaderObjectNode(const ShaderObjectNode &) = delete;
		ShaderObjectNode &operator = (const ShaderObjectNode &) = delete;
		virtual ~ShaderObjectNode();

		void Set(ShaderObject *pShader);
		void SetName(ShaderObject::Name name);

		ShaderObject *GetShaderObject();

		// The lookup key. Kept separate from the ShaderObject so the manager's
		// compare node can carry a name without owning a technique.
		ShaderObject::Name GetShaderName() const;

		virtual char *GetName() override;
		virtual void  Wash() override;
		virtual void  Dump() override;

	private:
		void privClear();

		// Borrowed -- see the note above. Never deleted here.
		ShaderObject      *poShader;

		// Kept separately so the compare node can carry a name without owning
		// a ShaderObject at all.
		ShaderObject::Name privName;
	};
}

#endif   // SHADER_OBJECT_NODE_H

// ---  End of File ---
