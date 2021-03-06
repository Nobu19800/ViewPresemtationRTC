// This file is generated by omniidl (C++ backend) - omniORB_4_1. Do not edit.

#include "DataBase.hh"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_1_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

static CORBA::TypeCode_ptr _0RL_tc_StringSeq = CORBA::TypeCode::PR_alias_tc("IDL:StringSeq:1.0", "StringSeq", CORBA::TypeCode::PR_sequence_tc(0, CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack), &_0RL_tcTrack), &_0RL_tcTrack);


const CORBA::TypeCode_ptr _tc_StringSeq = _0RL_tc_StringSeq;

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace DataBase { 
  const ::CORBA::TypeCode_ptr _tc_mDataBase = CORBA::TypeCode::PR_interface_tc("IDL:DataBase/mDataBase:1.0", "mDataBase", &_0RL_tcTrack);
} 
#else
const ::CORBA::TypeCode_ptr DataBase::_tc_mDataBase = CORBA::TypeCode::PR_interface_tc("IDL:DataBase/mDataBase:1.0", "mDataBase", &_0RL_tcTrack);
#endif

static void _0RL_StringSeq_marshal_fn(cdrStream& _s, void* _v)
{
  StringSeq* _p = (StringSeq*)_v;
  *_p >>= _s;
}
static void _0RL_StringSeq_unmarshal_fn(cdrStream& _s, void*& _v)
{
  StringSeq* _p = new StringSeq;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_StringSeq_destructor_fn(void* _v)
{
  StringSeq* _p = (StringSeq*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const StringSeq& _s)
{
  StringSeq* _p = new StringSeq(_s);
  _a.PR_insert(_0RL_tc_StringSeq,
               _0RL_StringSeq_marshal_fn,
               _0RL_StringSeq_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, StringSeq* _sp)
{
  _a.PR_insert(_0RL_tc_StringSeq,
               _0RL_StringSeq_marshal_fn,
               _0RL_StringSeq_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, StringSeq*& _sp)
{
  return _a >>= (const StringSeq*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const StringSeq*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_StringSeq,
                    _0RL_StringSeq_unmarshal_fn,
                    _0RL_StringSeq_marshal_fn,
                    _0RL_StringSeq_destructor_fn,
                    _v)) {
    _sp = (const StringSeq*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_DataBase_mmDataBase_marshal_fn(cdrStream& _s, void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  omniObjRef::_marshal(_o, _s);
}
static void _0RL_DataBase_mmDataBase_unmarshal_fn(cdrStream& _s, void*& _v)
{
  omniObjRef* _o = omniObjRef::_unMarshal(DataBase::mDataBase::_PD_repoId, _s);
  _v = _o;
}
static void _0RL_DataBase_mmDataBase_destructor_fn(void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  if (_o)
    omni::releaseObjRef(_o);
}

void operator<<=(::CORBA::Any& _a, DataBase::mDataBase_ptr _o)
{
  DataBase::mDataBase_ptr _no = DataBase::mDataBase::_duplicate(_o);
  _a.PR_insert(DataBase::_tc_mDataBase,
               _0RL_DataBase_mmDataBase_marshal_fn,
               _0RL_DataBase_mmDataBase_destructor_fn,
               _no->_PR_getobj());
}
void operator<<=(::CORBA::Any& _a, DataBase::mDataBase_ptr* _op)
{
  _a.PR_insert(DataBase::_tc_mDataBase,
               _0RL_DataBase_mmDataBase_marshal_fn,
               _0RL_DataBase_mmDataBase_destructor_fn,
               (*_op)->_PR_getobj());
  *_op = DataBase::mDataBase::_nil();
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, DataBase::mDataBase_ptr& _o)
{
  void* _v;
  if (_a.PR_extract(DataBase::_tc_mDataBase,
                    _0RL_DataBase_mmDataBase_unmarshal_fn,
                    _0RL_DataBase_mmDataBase_marshal_fn,
                    _0RL_DataBase_mmDataBase_destructor_fn,
                    _v)) {
    omniObjRef* _r = (omniObjRef*)_v;
    if (_r)
      _o = (DataBase::mDataBase_ptr)_r->_ptrToObjRef(DataBase::mDataBase::_PD_repoId);
    else
      _o = DataBase::mDataBase::_nil();
    return 1;
  }
  return 0;
}

