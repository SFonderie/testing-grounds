#pragma once

// Forward declaration.
class UComposite;
struct FName;

// Reference-based float wrapper.
// USTRUCT(BlueprintType)
struct FCompositeValue
{
	// GENERATED_BODY()

	// Derive the value from this composite.
	// UPROPERTY()
	UComposite* Reference = nullptr;

	// Value if the reference is null.
	// UPROPERTY()
	float ConstantValue = 0;
};

// Denotes how the composite modifier applies to the composite.
// UENUM()
enum class ECompositeModifierType
{
	DirectAddition,
	PercentAddition,
	Multiplication,
};

// Reference-enabled float modifier.
// USTRUCT(BlueprintType)
struct FCompositeModifier : public FCompositeValue
{
	
};
