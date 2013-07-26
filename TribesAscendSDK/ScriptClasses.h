#pragma once
#include <string>

class ScriptClass;
class ScriptObject;
class ScriptFunction;
class ScriptStruct;
class ScriptState;

typedef unsigned __int64 QWord;

template< class T > class ScriptArray
{
protected:
	T *data_;
	int count_;
	int max_;

public:
	ScriptArray()
	{
		data_ = NULL;
		count_ = max_ = 0;
	}

	inline int count()
	{
		return count_;
	}

	inline T *data()
	{
		return data_;
	}

	void Add( T new_data )
	{
		data_ = ( T* )( realloc( data_, sizeof( T ) * ++count_ ) );
		max_ = count_;
		data[ count_ ] = new_data;
	}

	T& operator ()( int i )
	{
		return data_[ i ];
	}

	friend class ScriptString;
};

class ScriptString
{
	ScriptArray< wchar_t > string;

public:
	ScriptString( wchar_t* string_ )
	{
		string.count_ = wcslen( string_ ) + 1;
		string.data_ = ( wchar_t* )( realloc( string.data_, sizeof( wchar_t ) * string.count_ ) );
		wcscpy_s( string.data_, wcslen( string_ ) + 1, string_ );
	}

	char* c_str()
	{
		char* buf = (char*)calloc(1, string.count());
		size_t convLen = 0;
		wcstombs_s(&convLen, buf, string.count(), string.data(), string.count());
		return buf;
	}

	operator ScriptArray< wchar_t >()
	{
		return string;
	}
};

class ScriptNameEntry
{
	byte __padding__[ 0x10 ];
	char name_[ 0x10 ];

public:

	inline char *name()
	{
		return name_;
	}
};

class ScriptName
{
	int index_;
	int __padding__;

	static ScriptArray< ScriptNameEntry* > *name_array_;

public:
	inline static ScriptArray< ScriptNameEntry* > *name_array()
	{
		return name_array_;
	}

	inline static void set_name_array( ScriptArray< ScriptNameEntry* > *new_name_array )
	{
		name_array_ = new_name_array;
		OutputLog( "Name Array: 0x%X\n", new_name_array );
	}

	char *GetName()
	{
		if( index_ >= name_array()->count() )
		{
			return "Failed to get name";
		}

		return ( *name_array() )( index_ )->name();
	}
};

class ScriptObject
{
private:
	int object_internal_integer_;
	QWord object_flags_;
	ScriptObject *hash_next_;
	ScriptObject *hash_outer_next_;
	void *state_frame_;
	ScriptObject *linker_;
	void *linker_index_;
	int net_index_;
	ScriptObject *outer_;
	ScriptName name_;
	class ScriptClass *object_class_;
	ScriptObject *object_archetype_;

	static ScriptArray< ScriptObject* > *object_array_;

public:

	static ScriptArray< ScriptObject* > *object_array()
	{
		return object_array_;
	}

	static void set_object_array( ScriptArray< ScriptObject* > *new_object_array )
	{
		object_array_ = new_object_array;
		OutputLog( "Object Array: 0x%X\n", new_object_array );
	}

	template< class T > static T* Find( char *object_name )
	{
		if( *object_name == ':' ) //hack for global namespace in the generated headers
			object_name += 2;

		for( int i = 0; i < object_array()->count(); i++ )
		{
			ScriptObject *object = ( *object_array() )( i );
			if( !strcmp( object->GetFullName(), object_name ) )
			{
				return ( T* )( object );
			}
		}
		return NULL;
	}

	static void LogAll();
	bool IsA( ScriptClass *script_class );
	void GenerateHeader();
	static void GenerateHeaders();
	char *GetName();
	const char *GetFullName();

	inline QWord object_flags()
	{
		return object_flags_;
	}

	inline ScriptObject *outer()
	{
		return outer_;
	}

	inline ScriptName name()
	{
		return name_;
	}

	inline ScriptClass *object_class()
	{
		return object_class_;
	}

	enum ENetRole
	{
		ROLE_None               = 0,
		ROLE_SimulatedProxy     = 1,
		ROLE_AutonomousProxy    = 2,
		ROLE_Authority          = 3,
		ROLE_MAX                = 4,
	};

private:
	virtual void Vfunc00();
	virtual void Vfunc01();
	virtual void Vfunc02();
	virtual void Vfunc03();
	virtual void Vfunc04();
	virtual void Vfunc05();
	virtual void Vfunc06();
	virtual void Vfunc07();
	virtual void Vfunc08();
	virtual void Vfunc09();
	virtual void Vfunc10();
	virtual void Vfunc11();
	virtual void Vfunc12();
	virtual void Vfunc13();
	virtual void Vfunc14();
	virtual void Vfunc15();
	virtual void Vfunc16();
	virtual void Vfunc17();
	virtual void Vfunc18();
	virtual void Vfunc19();
	virtual void Vfunc20();
	virtual void Vfunc21();
	virtual void Vfunc22();
	virtual void Vfunc23();
	virtual void Vfunc24();
	virtual void Vfunc25();
	virtual void Vfunc26();
	virtual void Vfunc27();
	virtual void Vfunc28();
	virtual void Vfunc29();
	virtual void Vfunc30();
	virtual void Vfunc31();
	virtual void Vfunc32();
	virtual void Vfunc33();
	virtual void Vfunc34();
	virtual void Vfunc35();
	virtual void Vfunc36();
	virtual void Vfunc37();
	virtual void Vfunc38();
	virtual void Vfunc39();
	virtual void Vfunc40();
	virtual void Vfunc41();
	virtual void Vfunc42();
	virtual void Vfunc43();
	virtual void Vfunc44();
	virtual void Vfunc45();
	virtual void Vfunc46();
	virtual void Vfunc47();
	virtual void Vfunc48();
	virtual void Vfunc49();
	virtual void Vfunc50();
	virtual void Vfunc51();
	virtual void Vfunc52();
	virtual void Vfunc53();
	virtual void Vfunc54();
	virtual void Vfunc55();
	virtual void Vfunc56();
	virtual void Vfunc57();
	virtual void Vfunc58();
	virtual void Vfunc59();
	virtual void Vfunc60();
	virtual void Vfunc61();
	virtual void Vfunc62();
	virtual void Vfunc63();
	virtual void Vfunc64();
	virtual void Vfunc65();
public:
	virtual void ProcessEvent( class ScriptFunction* function, void *params, void *result );
};

class ScriptField : public ScriptObject
{
public:
	ScriptField *next_;

public:
	inline ScriptField *next()
	{
		return next_;
	}
};

class ScriptEnum : public ScriptField
{
private:
	ScriptArray<ScriptName> value_names_;

public:
	inline ScriptArray<ScriptName> value_names()
	{
		return value_names_;
	}
};

class ScriptConst : public ScriptField
{
private:
	ScriptString value_;

public:
	inline ScriptString value()
	{
		return value_;
	}
};

class ScriptStruct : public ScriptField
{
public:
	byte __padding0__[ 0x8 ];
	ScriptField *super_;
	ScriptField *children_;
	DWORD property_size_;
	byte __padding1__[ 0x3C ];

public:
	inline ScriptField *super()
	{
		return super_;
	}

	inline ScriptField *children()
	{
		return children_;
	}
};

class ScriptFunction : public ScriptStruct
{
	DWORD function_flags_;
	WORD native_;
	WORD rep_offset_;
	ScriptName friendly_name_;
	WORD num_params_;
	WORD params_size_;
	DWORD return_val_offset_;
	DWORD __padding__;
	void *function_;

public:

	inline WORD num_params()
	{
		return num_params_;
	}

	inline WORD params_size()
	{
		return params_size_;
	}

	inline DWORD function_flags()
	{
		return function_flags_;
	}

	inline void set_function_flags( DWORD new_flags )
	{
		function_flags_ = new_flags;
	}

	inline void *function()
	{
		return function_;
	}

	inline void set_function( void *function )
	{
		function_ = function;
	}

	inline void set_native( int native )
	{
		native_ = native;
	}

	inline DWORD return_val_offset()
	{
		return return_val_offset_;
	}

	static const DWORD kFuncFinal =		1 << 0;
	static const DWORD kFuncLatent =	1 << 3;
	static const DWORD kFuncSimulated =	1 << 8;
	static const DWORD kFuncExec =		1 << 9;
	static const DWORD kFuncNative =	1 << 10;
	static const DWORD kFuncEvent =		1 << 11;
};

class ScriptState : public ScriptStruct
{
	byte __padding__[ 0x48 ];
};

class ScriptClass : public ScriptState
{
	byte __padding__[ 0xFC ];
};

struct ScriptProperty : public ScriptField
{
	static const QWord kPropEdit			= 0x0000000000000001;
	static const QWord kPropConst			= 0x0000000000000002;
	static const QWord kPropInput			= 0x0000000000000004;
	static const QWord kPropExportObject	= 0x0000000000000008;
	static const QWord kPropOptionalParm	= 0x0000000000000010;
	static const QWord kPropNet				= 0x0000000000000020;
	static const QWord kPropEditConstArray	= 0x0000000000000040;
	static const QWord kPropParm			= 0x0000000000000080;
	static const QWord kPropOutParm			= 0x0000000000000100;
	static const QWord kPropSkipParm		= 0x0000000000000200;
	static const QWord kPropReturnParm		= 0x0000000000000400;
	static const QWord kPropCoerceParm		= 0x0000000000000800;
	static const QWord kPropNative      	= 0x0000000000001000;
	static const QWord kPropTransient   	= 0x0000000000002000;
	static const QWord kPropConfig      	= 0x0000000000004000;
	static const QWord kPropLocalized   	= 0x0000000000008000;
	static const QWord kPropTravel      	= 0x0000000000010000;
	static const QWord kPropEditConst   	= 0x0000000000020000;
	static const QWord kPropGlobalConfig	= 0x0000000000040000;
	static const QWord kPropComponent		= 0x0000000000080000;
	static const QWord kPropNeedCtorLink	= 0x0000000000400000;
	static const QWord kPropNoExport    	= 0x0000000000800000;
	static const QWord kPropNoClear			= 0x0000000002000000;
	static const QWord kPropEditInline		= 0x0000000004000000;
	static const QWord kPropEdFindable		= 0x0000000008000000;
	static const QWord kPropEditInlineUse	= 0x0000000010000000;
	static const QWord kPropDeprecated  	= 0x0000000020000000;
	static const QWord kPropEditInlineNotify= 0x0000000040000000;
	static const QWord kPropRepNotify		= 0x0000000100000000;
	static const QWord kPropInterp			= 0x0000000200000000;
	static const QWord kPropNonTransactional= 0x0000000400000000;

	DWORD array_dimensions;
	DWORD element_size;
	QWord property_flags;
	
	byte __padding1__[ 0x10 ];

	DWORD offset;

	byte __padding2__[ 0x1C ];
};

struct ScriptObjectProperty : public ScriptProperty
{
	ScriptClass *property_class;
};

struct ScriptBoolProperty : public ScriptProperty
{
	DWORD bit_mask;
};

struct ScriptByteProperty : public ScriptProperty
{
	ScriptEnum* enum_type;
};

struct Vector
{
	float x, y, z;

	Vector( float X = 0, float Y = 0, float Z = 0 )
	{
		x = X;
		y = Y;
		z = Z;
	}

	float Length()
	{
		if( x == 0.0f && y == 0.0f && z == 0.0f )
			return 0.0f;

		return sqrtf( x * x + y * y + z * z );
	}

	Vector operator *( float num )
	{
		return Vector( x * num, y * num, z * num );
	}

	friend Vector operator *( float num, const Vector &vec )
	{
		return Vector( vec.x * num, vec.y * num, vec.z * num );
	}

	Vector operator *=( float num )
	{
		x *= num;
		y *= num;
		z *= num;
		return *this;
	}

	Vector operator /( float num ) const
	{
		return Vector( x / num, y / num, z / num );
	}
	Vector operator /=( float num )
	{
		x /= num;
		y /= num;
		z /= num;
		return *this;
	}

	Vector operator +( const Vector &vec ) const
	{
		return Vector( x + vec.x, y + vec.y, z + vec.z );
	}

	Vector operator +=( const Vector &vec )
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	Vector operator -( const Vector &vec ) const
	{
		return Vector( x - vec.x, y - vec.y, z - vec.z );
	}

	Vector operator -=( const Vector &vec )
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}

	Vector GetNormal()
	{
		float magnitude = Length();
		Vector temp_vec = *this;
		temp_vec.x /= magnitude;
		temp_vec.y /= magnitude;
		temp_vec.z /= magnitude;
		return temp_vec;
	}
	
	float DotProduct( const Vector &vec )
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	Vector CrossProduct( const Vector &vec )
	{
		return Vector(y * vec.z - z * vec.y,
				z * vec.x - x * vec.z,
				x * vec.y - y * vec.x);
	}
};

struct Rotator
{
	int pitch, yaw, roll;

	Rotator( int pitch_ = 0, int yaw_ = 0, int roll_ = 0 )
	{
		pitch = pitch_;
		yaw = yaw_;
		roll = roll_;
	}

	Rotator operator *( float num )
	{
		return Rotator( ( int )( num * pitch ), ( int )( num * yaw ), ( int )( num * roll ) );
	}

	friend Rotator operator *( float num, const Rotator &rot )
	{
		return Rotator( ( int )( num * rot.pitch ), ( int )( num * rot.yaw ), ( int )( num * rot.roll ) );
	}

	Rotator operator *=( float num )
	{
		pitch	= ( int )( num * pitch );
		yaw		= ( int )( num * yaw );
		roll	= ( int )( num * roll );
		return *this;
	}

	Rotator operator /( float num )
	{
		return Rotator( ( int )( ( 1.0f / num ) * pitch ), ( int )( ( 1.0f / num ) * yaw ), ( int )( ( 1.0f / num ) * roll ) );
	}

	Rotator operator /=( float num )
	{
		pitch	= ( int )( ( 1.0f / num ) * pitch );
		yaw		= ( int )( ( 1.0f / num ) * yaw );
		roll	= ( int )( ( 1.0f / num ) * roll );
		return *this;
	}

	Rotator operator +( const Rotator &rot )
	{
		return Rotator( ( int )( pitch + rot.pitch ), ( int )( yaw + rot.yaw ), ( int )( roll + rot.roll ) );
	}

	Rotator operator +=( const Rotator &rot )
	{
		pitch	+= rot.pitch;
		yaw		+= rot.yaw;
		roll	+= rot.roll;
		return *this;
	}

	Rotator operator -( const Rotator &rot )
	{
		return Rotator( pitch - rot.pitch, yaw - rot.yaw, roll - rot.roll );
	}

	Rotator operator -=( const Rotator &rot )
	{
		pitch	-= rot.pitch;
		yaw		-= rot.yaw;
		roll	-= rot.roll;
		return *this;
	}

	Vector GetForward() //Thanks id software
	{
		float	 angle;
		float	 sin_pitch, cos_pitch;
		float	 sin_yaw, cos_yaw;

		angle = ( float )( pitch ) * ( 3.14159f * 2 / 65535 );
		sin_pitch = sin( angle );
		cos_pitch = cos( angle );

		angle = ( float )( yaw ) * ( 3.14159f * 2 / 65535 );
		sin_yaw = sin( angle );
		cos_yaw = cos( angle );

		Vector forward;

		forward.x = cos_pitch * cos_yaw;
		forward.y = cos_pitch * sin_yaw;
		forward.z = sin_pitch;
		return forward;
	}

	Vector GetRight() //Thanks id software
	{
		float	 angle;
		float	 sin_pitch, cos_pitch;
		float	 sin_yaw, cos_yaw;
		float	 sin_roll, cos_roll;

		angle = ( float )( pitch ) * ( 3.14159f * 2 / 65535 );
		sin_pitch = sin( angle );
		cos_pitch = cos( angle );

		angle = ( float )( yaw ) * ( 3.14159f * 2 / 65535 );
		sin_yaw = sin( angle );
		cos_yaw = cos( angle );
		
		angle = ( float )( roll ) * ( 3.14159f * 2 / 65535 );
		sin_roll = sin( angle );
		cos_roll = cos( angle );

		Vector right;

		right.x = ( -sin_roll * sin_pitch * cos_yaw + cos_roll * sin_yaw );
		right.y = ( -sin_roll * sin_pitch * sin_yaw - cos_roll * cos_yaw );
		right.z = sin_roll * cos_pitch;
		return right;
	}

	Vector GetUp() //Thanks id software
	{
		float	 angle;
		float	 sin_pitch, cos_pitch;
		float	 sin_yaw, cos_yaw;
		float	 sin_roll, cos_roll;

		angle = ( float )( pitch ) * ( 3.14159f * 2 / 65535 );
		sin_pitch = sin( angle );
		cos_pitch = cos( angle );

		angle = ( float )( yaw ) * ( 3.14159f * 2 / 65535 );
		sin_yaw = sin( angle );
		cos_yaw = cos( angle );
		
		angle = ( float )( roll ) * ( 3.14159f * 2 / 65535 );
		sin_roll = sin( angle );
		cos_roll = cos( angle );

		Vector up;

		up.x = ( cos_roll * sin_pitch * cos_yaw + sin_roll * sin_yaw );
		up.y = ( cos_roll * sin_pitch * sin_yaw - sin_roll * cos_yaw );
		up.z = -cos_roll * cos_pitch;
		return up;
	}
};