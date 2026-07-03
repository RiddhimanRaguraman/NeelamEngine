//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef MAT4_HINT_H
#define MAT4_HINT_H

#include "Mat4.h"

#ifdef MATH_USE_HINTS

namespace Azul
{
	class Mat4Hint : public Mat4
	{
	public:

		enum class Hint : uint32_t
		{
			Generalize = 0x0,        // generalize 4x4 inverse  (no flags)
			Rot = 0x1,               // matrix inverse is M.T()
			Trans = 0x2,             // matrix inverse is M(-trans)
			RotTrans = 0x3,          // rot and trans  A_inv is A.T() 
			Scale = 0x4,             // matrix invers is M(1/scale)
			RotScale = 0x5,          // Rot and Scale no translate
			TransScale = 0x6,        // Trans and Scale no Translate
			Affine = 0x7             // generalize Affine
		};

		inline Hint GetHint() const
		{
			Hint h;

			// test if m15 ~= 1.0f (ignore last 3 bits flags, actually 8 bits to account for noise)

			if ((this->_u_m15 & 0xFFFFFF00) == 0x3f800000 || (this->_u_m15 & 0xFFFFFF00) == 0x3f7fff00)
			{
				h = (Hint) (this->_u_m15 & 0x7);
			}
			else
			{
				h = Hint::Generalize;
			}

			return h;
		}

		inline void privClearHint()
		{
			this->_u_m15 &= (unsigned int) (0xFFFFFFF8);
		}

		inline void privSetGeneralHint()
		{
			this->_u_m15 &= (unsigned int) (0xFFFFFFF8);
		}

		inline void privSetScaleHint()
		{
			this->_u_m15 |= (unsigned int) (Mat4Hint::Hint::Scale);
		}

		inline void privSetRotHint()
		{
			this->_u_m15 |= (unsigned int) (Mat4Hint::Hint::Rot);
		}

		inline void privSetTransHint()
		{
			this->_u_m15 |= (unsigned int) (Mat4Hint::Hint::Trans);
		}

		inline void privSetCopyHint() const
		{
			// do nothing
		}

		inline bool privTestTransBit() const
		{
			return (this->_u_m15 & (unsigned int) (Mat4Hint::Hint::Trans));
		}

		inline void privSetNewHint(Hint A, Hint B)
		{
			Hint h;

			if (A == Hint::Generalize || B == Hint::Generalize)
			{
				h = Hint::Generalize;
			}
			else // hint isn't a generalized matrix
			{
				h = (Hint) ((unsigned int) A | (unsigned int) B);
			}

			// Set it.
			this->_u_m15 &= (unsigned int) 0xFFFFFFF8;
			this->_u_m15 |= (unsigned int) h;
		}

	};
}

#endif

#endif


//--- End of File ---
