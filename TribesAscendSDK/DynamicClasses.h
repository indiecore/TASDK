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
typedef ArithmeticProperty< QWord > QWordProperty;

class RotatorProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

	inline Rotator *GetRotator()
	{
		return ( Rotator* )( thisptr_ + offset_ );
	}

public:

	RotatorProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( Rotator new_val )
		{ *GetRotator() = new_val; }

	operator Rotator()
		{ return *GetRotator(); }

	Rotator operator *( float num )
	{
		return Rotator( ( int )( num * GetRotator()->pitch ), ( int )( num * GetRotator()->yaw ), ( int )( num * GetRotator()->roll ) );
	}

	Rotator operator *=( float num )
	{
		GetRotator()->pitch	= ( int )( num * GetRotator()->pitch );
		GetRotator()->yaw	= ( int )( num * GetRotator()->yaw );
		GetRotator()->roll	= ( int )( num * GetRotator()->roll );
		return *GetRotator();
	}

	Rotator operator /( float num )
	{
		return Rotator( ( int )( ( 1.0f / num ) * GetRotator()->pitch ), ( int )( ( 1.0f / num ) * GetRotator()->yaw ), ( int )( ( 1.0f / num ) * GetRotator()->roll ) );
	}

	Rotator operator /=( float num )
	{
		GetRotator()->pitch	= ( int )( ( 1.0f / num ) * GetRotator()->pitch );
		GetRotator()->yaw	= ( int )( ( 1.0f / num ) * GetRotator()->yaw );
		GetRotator()->roll	= ( int )( ( 1.0f / num ) * GetRotator()->roll );
		return *GetRotator();
	}

	Rotator operator +( const Rotator &rot )
	{
		return Rotator( ( int )( GetRotator()->pitch + rot.pitch ), ( int )( GetRotator()->yaw + rot.yaw ), ( int )( GetRotator()->roll + rot.roll ) );
	}

	Rotator operator +=( const Rotator &rot )
	{
		GetRotator()->pitch	+= rot.pitch;
		GetRotator()->yaw	+= rot.yaw;
		GetRotator()->roll	+= rot.roll;
		return *GetRotator();
	}

	Rotator operator -( const Rotator &rot )
	{
		return Rotator( GetRotator()->pitch - rot.pitch, GetRotator()->yaw - rot.yaw, GetRotator()->roll - rot.roll );
	}

	Rotator operator -=( const Rotator &rot )
	{
		GetRotator()->pitch	-= rot.pitch;
		GetRotator()->yaw	-= rot.yaw;
		GetRotator()->roll	-= rot.roll;
		return *GetRotator();
	}

	Vector GetForward()
	{
		return GetRotator()->GetForward();
	}

	Vector GetRight()
	{
		return GetRotator()->GetForward();
	}

	Vector GetUp()
	{
		return GetRotator()->GetForward();
	}
};

class VectorProperty
{
	DWORD offset_;
	uintptr_t thisptr_;

	inline Vector *GetVector()
	{
		return ( Vector* )( thisptr_ + offset_ );
	}

public:

	VectorProperty( void *thisptr, DWORD offset, DWORD bit_mask )
	{
		thisptr_ = ( uintptr_t )( thisptr );
		offset_ = offset;
	}

	void operator =( Vector new_val )
		{ *GetVector() = new_val; }

	operator Vector()
		{ return *GetVector(); }

	Vector operator *( float num )
	{
		return Vector( GetVector()->x * num, GetVector()->y * num, GetVector()->z * num );
	}

	Vector operator *=( float num )
	{
		GetVector()->x	= num * GetVector()->x;
		GetVector()->y	= num * GetVector()->y;
		GetVector()->z	= num * GetVector()->z;
		return *GetVector();
	}

	Vector operator /( float num )
	{
		return Vector( GetVector()->x / num, GetVector()->y / num, GetVector()->z / num );
	}

	Vector operator /=( float num )
	{
		GetVector()->x	= GetVector()->x / num;
		GetVector()->y	= GetVector()->y / num;
		GetVector()->z	= GetVector()->z / num;
		return *GetVector();
	}

	Vector operator +( const Vector &vec )
	{
		return Vector( GetVector()->x + vec.x, GetVector()->y + vec.y, GetVector()->z + vec.z );
	}

	Vector operator +=( const Vector &vec )
	{
		GetVector()->x	+= vec.x;
		GetVector()->y	+= vec.y;
		GetVector()->z	+= vec.z;
		return *GetVector();
	}

	Vector operator -( const Vector &vec )
	{
		return Vector( GetVector()->x - vec.x, GetVector()->y - vec.y, GetVector()->z - vec.z );
	}

	Vector operator -=( const Vector &vec )
	{
		GetVector()->x	-= vec.x;
		GetVector()->y	-= vec.y;
		GetVector()->z	-= vec.z;
		return *GetVector();
	}

	float Length()
	{
		return GetVector()->Length();
	}

	float DotProduct( const Vector &vec )
	{
		return GetVector()->DotProduct( vec );
	}

	Vector CrossProduct( const Vector &vec )
	{
		return GetVector()->CrossProduct( vec );
	}
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