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
public:
	int object_internal_integer_;
	QWord object_flags_;
	void *hash_next_;
	void *hash_outer_next_;
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

	static ScriptObject* Find( char *object_name );
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

private:
	virtual void Vfunc00() = 0;
	virtual void Vfunc01() = 0;
	virtual void Vfunc02() = 0;
	virtual void Vfunc03() = 0;
	virtual void Vfunc04() = 0;
	virtual void Vfunc05() = 0;
	virtual void Vfunc06() = 0;
	virtual void Vfunc07() = 0;
	virtual void Vfunc08() = 0;
	virtual void Vfunc09() = 0;
	virtual void Vfunc10() = 0;
	virtual void Vfunc11() = 0;
	virtual void Vfunc12() = 0;
	virtual void Vfunc13() = 0;
	virtual void Vfunc14() = 0;
	virtual void Vfunc15() = 0;
	virtual void Vfunc16() = 0;
	virtual void Vfunc17() = 0;
	virtual void Vfunc18() = 0;
	virtual void Vfunc19() = 0;
	virtual void Vfunc20() = 0;
	virtual void Vfunc21() = 0;
	virtual void Vfunc22() = 0;
	virtual void Vfunc23() = 0;
	virtual void Vfunc24() = 0;
	virtual void Vfunc25() = 0;
	virtual void Vfunc26() = 0;
	virtual void Vfunc27() = 0;
	virtual void Vfunc28() = 0;
	virtual void Vfunc29() = 0;
	virtual void Vfunc30() = 0;
	virtual void Vfunc31() = 0;
	virtual void Vfunc32() = 0;
	virtual void Vfunc33() = 0;
	virtual void Vfunc34() = 0;
	virtual void Vfunc35() = 0;
	virtual void Vfunc36() = 0;
	virtual void Vfunc37() = 0;
	virtual void Vfunc38() = 0;
	virtual void Vfunc39() = 0;
	virtual void Vfunc40() = 0;
	virtual void Vfunc41() = 0;
	virtual void Vfunc42() = 0;
	virtual void Vfunc43() = 0;
	virtual void Vfunc44() = 0;
	virtual void Vfunc45() = 0;
	virtual void Vfunc46() = 0;
	virtual void Vfunc47() = 0;
	virtual void Vfunc48() = 0;
	virtual void Vfunc49() = 0;
	virtual void Vfunc50() = 0;
	virtual void Vfunc51() = 0;
	virtual void Vfunc52() = 0;
	virtual void Vfunc53() = 0;
	virtual void Vfunc54() = 0;
	virtual void Vfunc55() = 0;
	virtual void Vfunc56() = 0;
	virtual void Vfunc57() = 0;
	virtual void Vfunc58() = 0;
	virtual void Vfunc59() = 0;
	virtual void Vfunc60() = 0;
	virtual void Vfunc61() = 0;
	virtual void Vfunc62() = 0;
	virtual void Vfunc63() = 0;
	virtual void Vfunc64() = 0;
public:
	virtual void ProcessEvent( class ScriptFunction* function, void* params, void* result ) = 0;
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

	Vector operator *( float num ) const
	{
		return Vector( x * num, y * num, z * num );
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

	friend Vector operator *( float num, Vector const &vec )
	{
		return Vector( vec.x * num, vec.y * num, vec.z * num );
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
	
	float DotProduct( const Vector &vec ) const
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	Vector CrossProduct( const Vector &vec ) const
	{
		return Vector(y * vec.z - z * vec.y,
				z * vec.x - x * vec.z,
				x * vec.y - y * vec.x);
	}

	class ShortVector ToShortVector();
};

struct ShortVector
{
	short x, y, z;

	ShortVector( short X = 0, short Y = 0, short Z = 0 )
	{
		x = X;
		y = Y;
		z = Z;
	}

	float Length()
	{
		if( x == 0.0f && y == 0.0f && z == 0.0f )
			return 0.0f;

		return sqrtf( ( float )( x * x + y * y + z * z ) );
	}

	ShortVector operator *( float num ) const
	{
		return ShortVector( ( short )( ( float )( x ) * num ), ( short )( ( float )( y ) * num ), ( short )( ( float )( z ) * num ) );
	}
	ShortVector operator *=( float num )
	{
		x *= num;
		y *= num;
		z *= num;
		return *this;
	}

	ShortVector operator /( float num ) const
	{
		return ShortVector( x / num, y / num, z / num );
	}
	ShortVector operator /=( float num )
	{
		x /= num;
		y /= num;
		z /= num;
		return *this;
	}

	friend ShortVector operator *( float num, ShortVector const &vec )
	{
		return ShortVector( vec.x * num, vec.y * num, vec.z * num );
	}

	ShortVector operator +( const ShortVector &vec ) const
	{
		return ShortVector( x + vec.x, y + vec.y, z + vec.z );
	}
	ShortVector operator +=( const ShortVector &vec )
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	ShortVector operator -( const ShortVector &vec ) const
	{
		return ShortVector( x - vec.x, y - vec.y, z - vec.z );
	}

	ShortVector operator -=( const ShortVector &vec )
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}

	ShortVector GetNormal()
	{
		float magnitude = Length();
		ShortVector temp_vec = *this;
		temp_vec.x /= magnitude;
		temp_vec.y /= magnitude;
		temp_vec.z /= magnitude;
		return temp_vec;
	}
	
	float DotProduct( const ShortVector &vec ) const
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	ShortVector CrossProduct( const ShortVector &vec ) const
	{
		return ShortVector(y * vec.z - z * vec.y,
				z * vec.x - x * vec.z,
				x * vec.y - y * vec.x);
	}

	Vector ToFloatVector();
};

typedef Vector Rotator;
typedef ShortVector ShortRotator;