//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef COMMAND_H
#define COMMAND_H

//---------------------------------------------------------------------------
// class Command  (abstract)
//
// One unit of cross-thread work. A producer thread NEWs a concrete command and
// posts it to the consumer's inbox (QueueMan); the consumer pops it and calls
// Execute() ON ITS OWN THREAD. That is the entire actor model -- no thread ever
// touches another thread's data directly.
//
// OWNERSHIP -- all three rules are required for a leak-free run:
//   * The CONSUMER owns the command; Execute() ends with delete this.
//   * If the post FAILS (inbox full), it was never handed over -- the SENDER
//     deletes it.
//   * Anything still queued at shutdown is never executed, so QueueMan::Destroy
//     drains and deletes the remainder.
//---------------------------------------------------------------------------

namespace Neelam
{
	class Command
	{
	public:
		Command() = default;
		Command(const Command &) = delete;
		Command &operator = (const Command &) = delete;
		virtual ~Command() = default;

		// Runs on the CONSUMER's thread. Implementations end with `delete this`.
		virtual void Execute() = 0;
	};
}

#endif   // COMMAND_H

// ---  End of File ---
