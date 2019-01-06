#include "program.hpp"
#include "syntaxtree.hpp"
#include "tuple.hpp"

#include "base/arguments.hpp"
#include "base/assignment.hpp"
#include "base/bracket.hpp"
#include "base/calculation.hpp"
#include "base/call.hpp"
#include "base/import.hpp"
#include "base/name.hpp"
#include "base/return.hpp"
#include "base/terminated.hpp"
#include "base/variable.hpp"

#include "blocks/countedFor.hpp"
#include "blocks/elseIf.hpp"
#include "blocks/for.hpp"
#include "blocks/function.hpp"
#include "blocks/if.hpp"
#include "blocks/ifElse.hpp"
#include "blocks/ifElseIf.hpp"
#include "blocks/ifElseIfElse.hpp"
#include "blocks/returnableBlock.hpp"

#include "values/array.hpp"
#include "values/arrayAccess.hpp"
#include "values/empty.hpp"
#include "values/littlBool.hpp"
#include "values/littlDec.hpp"
#include "values/littlInt.hpp"
#include "values/littlString.hpp"
