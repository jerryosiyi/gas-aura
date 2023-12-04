// Copyright New Dawn Group LTD 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AuraAttributeInfo.generated.h"

USTRUCT(BlueprintType)
struct FAuraAttributeInfoStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDesc;

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.f;
};


UCLASS()
class AURA_API UAuraAttributeInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAuraAttributeInfoStruct> AttributeInformation;

	FAuraAttributeInfoStruct FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const;
};
