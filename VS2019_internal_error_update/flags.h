#ifndef FLAGS_H
#define FLAGS_H

#include <array>

struct FlagTraits {
	const char* m_name;
};

class Flags 
{
	enum { systemFlags_count = 1 };

public:

	enum class use : char
	{
		no			= '-',
		yes			= '+',
		Count = 2, Index = 1, Default = yes
	};

	static constexpr std::array<FlagTraits, systemFlags_count> m_SystemFlagsTraits =
	{
		#define FLAG_TRAITS_CASE(flag)	FlagTraits{ #flag },
		FLAG_TRAITS_CASE(use)
		#undef FLAG_TRAITS_CASE
	};

};

#endif
