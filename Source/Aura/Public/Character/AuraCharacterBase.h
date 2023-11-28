// Copyright New Dawn Group LTD 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interaction/AuraCombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UGameplayEffect;
class UAuraAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public IAuraCombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;
	
	virtual void BeginPlay() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
	virtual void InitAbilityActorInfo();

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass, float Level) const;

	void InitializeDefaultAttributes() const;
};
