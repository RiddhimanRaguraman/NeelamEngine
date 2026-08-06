//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderObjectNodeMan.h"
#include "ShaderObjectNodeCompareStrategyEnumName.h"
#include "DLinkMan.h"

namespace Neelam::vk
{
	ShaderObjectNodeMan       *ShaderObjectNodeMan::posInstance        = nullptr;
	Azul::CompareStrategyBase *ShaderObjectNodeMan::posEnumNameCompare = nullptr;

	ShaderObjectNodeMan::ShaderObjectNodeMan(int reserveNum, int reserveGrow)
		: Azul::ManBase(new Azul::DLinkMan(), new Azul::DLinkMan(), reserveNum, reserveGrow),
		  poNodeCompare(nullptr)
	{
		this->proFillReservedPool(reserveNum);

		// Lives for the manager's lifetime; carries only the search key.
		this->poNodeCompare = new ShaderObjectNode();
	}

	ShaderObjectNodeMan::~ShaderObjectNodeMan()
	{
		delete this->poNodeCompare;
		this->poNodeCompare = nullptr;

		Azul::Iterator *pIt = this->baseGetActiveIterator();
		pIt->First();
		while (!pIt->IsDone())
		{
			ShaderObjectNode *pDeleteMe = (ShaderObjectNode *)pIt->Curr();
			pIt->Next();
			delete pDeleteMe;		// deletes the NODE only -- see ShaderObjectNode
		}

		pIt = this->baseGetReserveIterator();
		pIt->First();
		while (!pIt->IsDone())
		{
			ShaderObjectNode *pDeleteMe = (ShaderObjectNode *)pIt->Curr();
			pIt->Next();
			delete pDeleteMe;
		}
	}

	void ShaderObjectNodeMan::Create(int reserveNum, int reserveGrow)
	{
		assert(reserveNum >= 0);
		assert(reserveGrow > 0);
		assert(posInstance == nullptr);

		posInstance = new ShaderObjectNodeMan(reserveNum, reserveGrow);

		if (posEnumNameCompare == nullptr)
		{
			posEnumNameCompare = new ShaderObjectNodeCompareStrategyEnumName();
		}
	}

	void ShaderObjectNodeMan::Destroy()
	{
		assert(posInstance != nullptr);

		delete ShaderObjectNodeMan::posEnumNameCompare;
		ShaderObjectNodeMan::posEnumNameCompare = nullptr;

		delete ShaderObjectNodeMan::posInstance;
		ShaderObjectNodeMan::posInstance = nullptr;
	}

	ShaderObjectNodeMan *ShaderObjectNodeMan::privGetInstance()
	{
		assert(posInstance != nullptr);
		return posInstance;
	}

	ShaderObjectNode *ShaderObjectNodeMan::Add(ShaderObject *pShader)
	{
		assert(pShader);

		ShaderObjectNodeMan *pMan = ShaderObjectNodeMan::privGetInstance();

		ShaderObjectNode *pNode = static_cast<ShaderObjectNode *>(pMan->baseAddToFront());
		pNode->Set(pShader);
		return pNode;
	}

	ShaderObject *ShaderObjectNodeMan::Find(ShaderObject::Name name)
	{
		// Deliberately does NOT assert on a miss: a cross-thread command whose
		// technique was destroyed mid-flight lands here, and nullptr is the
		// correct, expected answer.
		ShaderObjectNodeMan *pMan = ShaderObjectNodeMan::privGetInstance();

		pMan->pCompareStrategy = ShaderObjectNodeMan::posEnumNameCompare;
		assert(pMan->pCompareStrategy);

		pMan->poNodeCompare->SetName(name);

		ShaderObjectNode *pNode =
			static_cast<ShaderObjectNode *>(pMan->baseFind(pMan->poNodeCompare));

		return (pNode != nullptr) ? pNode->GetShaderObject() : nullptr;
	}

	void ShaderObjectNodeMan::Remove(ShaderObjectNode *pNode)
	{
		assert(pNode);
		ShaderObjectNodeMan::privGetInstance()->baseRemove(pNode);
	}

	void ShaderObjectNodeMan::Dump()
	{
		Debug::out("\n   ------ ShaderObjectNodeMan Dump ------\n");
		ShaderObjectNodeMan::privGetInstance()->baseDump();
	}

	Azul::DLink *ShaderObjectNodeMan::derivedCreateNode()
	{
		return new ShaderObjectNode();
	}
}

// ---  End of File ---
