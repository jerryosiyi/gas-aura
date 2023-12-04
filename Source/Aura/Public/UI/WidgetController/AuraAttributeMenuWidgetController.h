// Copyright New Dawn Group LTD 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AuraWidgetController.h"
#include "AuraAttributeMenuWidgetController.generated.h"

struct FGameplayTag;
struct FGameplayAttribute;
struct FAuraAttributeInfoStruct;
class UAuraAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FAuraAttributeInfoStruct&, Info);

UCLASS(BlueprintType, Blueprintable)
class AURA_API UAuraAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;
	
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAuraAttributeInfo> AttributeInfo;

private:
	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const;
};
