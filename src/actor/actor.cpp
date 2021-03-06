#include "stdafx.h"
#include <lax/actor/actor.hpp>
#include <basetsd.h>

namespace lax 
{
namespace actor 
{

util::sequence<uint32_t, std::recursive_mutex> actor::id_seq_(1, MAXUINT32, 1024);

actor::actor(weak_ptr parent)
	: parent_(parent)
	, id_(id_seq_.next())
{
	push_type(typeid(actor));
}

actor::~actor()
{
	finish(); // make it sure

	id_seq_.release(id_);
}

bool actor::start()
{
	auto rc = on_start();
	RETURN_IF(!rc, false);

	comps_.apply([](component::ptr comp) { return comp->start(); });

	if (rc)
	{
		state_ = state::started;
	}

	return rc;
}

void actor::execute()
{
	VERIFY(state_ == state::started);

	on_execute();
}

void actor::finish()
{
	RETURN_IF(state_ == state::constructed);
	RETURN_IF(state_ == state::finished);

	on_finish();

	state_ = state::finished;
}

bool actor::on_start()
{
	return true;
}

void actor::on_execute()
{
}

void actor::on_finish()
{
}


} // actor 
} // lax
