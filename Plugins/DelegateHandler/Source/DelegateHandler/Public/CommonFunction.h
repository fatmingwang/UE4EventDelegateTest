#pragma once

#define DELETE_TMAP(e_Map)									\
{															\
	for (auto It = e_Map.CreateConstIterator(); It; ++It)	\
	{														\
		auto l_pValue = It->Value;							\
		if (l_pValue)										\
			delete l_pValue;								\
	}														\
	e_Map.Empty();											\
}

#define DELETE_TARRAY(e_Array)								\
{															\
	for (auto l_pValue : e_Array)							\
	{														\
		if (l_pValue)										\
			delete l_pValue;								\
	}														\
	e_Array.Empty();										\
}

#define	DELETE_VECTOR(e_Vector)								\
	for (auto l_pValue : e_Vector)							\
	{														\
		if (l_pValue)										\
			delete l_pValue;								\
	}														\
	e_Vector.clear()