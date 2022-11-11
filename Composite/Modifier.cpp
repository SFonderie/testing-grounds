#include "Modifier.h"

Modifier::Modifier() : m_Type(ADD_DIRECT), m_Value(0), m_Delegate(nullptr), m_Order(0) {  }

Modifier::Modifier(const Modifier& base)
{
	m_Type = base.m_Type;
	m_Value = base.m_Value;
	m_Delegate = base.m_Delegate;
	m_Order = base.m_Order;
}

Modifier::Modifier(ModifierType type, float value) : m_Type(type), m_Value(value), m_Delegate(nullptr), m_Order(0) {  }

Modifier::Modifier(ModifierType type, float(*delegate)()) : m_Type(type), m_Value(0), m_Delegate(delegate), m_Order(0) {  }

Modifier::~Modifier() {  }

float Modifier::GetValue() const
{
	if (m_Delegate) return (*m_Delegate)();
	return m_Value;
}
