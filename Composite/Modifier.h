#ifndef MODIFIER_H
#define MODIFIER_H

struct Modifier
{
	/// <summary>
	/// Apply the modifier using the following operation.
	/// </summary>
	enum ModifierType
	{
		ADD_DIRECT,
		ADD_PERCENT,
		MULTIPLY,
	};

private:

	// Operation with which to apply the value.
	ModifierType m_Type;

	// Base value if it's a value.
	float m_Value;

	// Base value if it's a function.
	float(*m_Delegate)();

	// Sort order.
	int m_Order;

public:

	// Default constructor.
	Modifier();

	// Copy constructor.
	Modifier(const Modifier& base);

	// Flat value.
	Modifier(ModifierType type, float value);

	// Delegate value.
	Modifier(ModifierType type, float(*delegate)());

	~Modifier();

	// Returns the value.
	float GetValue() const;
};

#endif
