class NameProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	NameProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	operator ScriptName*()
		{ return ( *( ScriptName** )( thisptr_ + offset_ ) ); }
};

class StrProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	StrProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	operator wchar_t*()
		{ return ( ( ScriptArray< wchar_t >* )( thisptr_ + offset_ ) )->data(); }
};

template< class T > class ArithmeticProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	ArithmeticProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( T new_val )
		{ *( T* )( thisptr_ + offset_ ) = new_val; }

	operator T()
		{ return *( T* )( thisptr_ + offset_ ); }

	void operator +=( T val )
		{ *( T* )( thisptr_ + offset_ ) += val; }
	void operator -=( T val )
		{ *( T* )( thisptr_ + offset_ ) -= val; }
	void operator /=( T val )
		{ *( T* )( thisptr_ + offset_ ) /= val; }
	void operator *=( T val )
		{ *( T* )( thisptr_ + offset_ ) *= val; }

	T operator +( T val )
		{ return *( T* )( thisptr_ + offset_ ) + val; }
	T operator -( T val )
		{ return *( T* )( thisptr_ + offset_ ) - val; }
	T operator /( T val )
		{ return *( T* )( thisptr_ + offset_ ) / val; }
	T operator *( T val )
		{ return *( T* )( thisptr_ + offset_ ) * val; }
};

template< class T > class NonArithmeticProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	NonArithmeticProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( T new_val )
		{ *( T* )( thisptr_ + offset_ ) = new_val; }

	operator T()
		{ return *( T* )( thisptr_ + offset_ ); }
};

class BoolProperty
{
	DWORD offset_;
	uintptr_t thisptr_;
	DWORD bit_mask_;

public:

	BoolProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
		bit_mask_ = bit_mask;
	}

	void operator =( bool new_val )
	{
		if( new_val )
			*( DWORD* )( thisptr_ + offset_ ) |= bit_mask_;
		else
			*( DWORD* )( thisptr_ + offset_ ) &= ~bit_mask_;
	}

	operator bool()
		{ return ( *( DWORD* )( thisptr_ + offset_ ) & bit_mask_ ) != 0; }
};

typedef ArithmeticProperty< byte > ByteProperty;
typedef ArithmeticProperty< int > IntProperty;
typedef ArithmeticProperty< float > FloatProperty;

class RotatorProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	RotatorProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( ShortRotator new_val )
		{ *( ShortRotator* )( thisptr_ + offset_ ) = new_val; }

	void operator =( Rotator new_val )
		{ *( ShortVector* )( thisptr_ + offset_ ) = new_val.ToShortVector(); }

	operator ShortRotator()
		{ return *( ShortRotator* )( thisptr_ + offset_ ); }

	operator Rotator()
		{ return ( *( ShortRotator* )( thisptr_ + offset_ ) ).ToFloatVector(); }
};

class VectorProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	VectorProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( ShortVector new_val )
		{ *( ShortVector* )( thisptr_ + offset_ ) = new_val; }

	void operator =( Vector new_val )
		{ *( ShortVector* )( thisptr_ + offset_ ) = new_val.ToShortVector(); }

	operator ShortVector()
		{ return *( ShortVector* )( thisptr_ + offset_ ); }

	operator Vector()
		{ return ( *( ShortVector* )( thisptr_ + offset_ ) ).ToFloatVector(); }
};

template< class T > class ObjectProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

public:

	ObjectProperty( void *thisptr, DWORD offset )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( void *new_val )
		{ *( T** )( thisptr_ + offset_ ) = new_val; }

	operator T*()
		{ return *( T** )( thisptr_ + offset_ ); }

	T* object()
		{ return *( T** )( thisptr_ + offset_ ); }
};