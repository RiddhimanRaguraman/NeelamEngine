//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_OBJECT_NODE_MAN_H
#define SHADER_OBJECT_NODE_MAN_H

#include "ManBase.h"
#include "ShaderObjectNode.h"
#include "ShaderObject.h"

namespace Neelam::vk
{
	//-----------------------------------------------------------------------
	// class ShaderObjectNodeMan  (singleton)
	//
	// Find a technique by ShaderObject::Name. Same ManBase/DLink shape as
	// CameraNodeMan.
	//
	// THIS IS THE CROSS-THREAD SAFETY MECHANISM. A command posted from
	// another thread carries a NAME, never a ShaderObject*. The engine thread
	// calls Find() when the command finally executes: if the technique was
	// destroyed in the meantime it is no longer registered, Find returns
	// nullptr, and the command bails instead of writing through a dangling
	// pointer. Handles do not do this -- they are a self-pin, not a weak ref.
	//
	// Nodes BORROW their ShaderObject (see ShaderObjectNode) -- Game owns the
	// techniques as members, so nothing here deletes one.
	//-----------------------------------------------------------------------
	class ShaderObjectNodeMan : public Azul::ManBase
	{
	public:
		static void Create(int reserveNum = 0, int reserveGrow = 1);
		static void Destroy();

		static ShaderObjectNode *Add(ShaderObject *pShader);

		// nullptr if no technique with that name is registered -- which is the
		// expected answer for a stale cross-thread command, not an error.
		static ShaderObject *Find(ShaderObject::Name name);

		static void Remove(ShaderObjectNode *pNode);
		static void Dump();

		ShaderObjectNodeMan(const ShaderObjectNodeMan &) = delete;
		ShaderObjectNodeMan &operator = (const ShaderObjectNodeMan &) = delete;

	private:
		ShaderObjectNodeMan() = delete;
		ShaderObjectNodeMan(int reserveNum, int reserveGrow);
		virtual ~ShaderObjectNodeMan();

		static ShaderObjectNodeMan *privGetInstance();

	protected:
		virtual Azul::DLink *derivedCreateNode() override;

	private:
		ShaderObjectNode *poNodeCompare;

		static ShaderObjectNodeMan        *posInstance;
		static Azul::CompareStrategyBase  *posEnumNameCompare;
	};
}

#endif   // SHADER_OBJECT_NODE_MAN_H

// ---  End of File ---
