// Copyright New Dawn Group LTD 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FORCEINLINE FWidgetControllerParams() {}
	
	explicit FORCEINLINE FWidgetControllerParams(
		APlayerController* PC, APlayerState* PS,
		UAbilitySystemComponent* ASC, UAttributeSet* AS)
		: PlayerController(PC)
		, PlayerState(PS)
		, AbilitySystemComponent(ASC)
		, AttributeSet(AS)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Controller")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Controller")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

	virtual void BroadcastInitialValues();

	virtual void BindCallbacksToDependencies();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet;
};
