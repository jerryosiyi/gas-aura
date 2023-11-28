// Copyright New Dawn Group LTD 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/AuraEnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IAuraEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	//~ Begin Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	//~ End Enemy Interface

	//~ Begin Combat Interface
	virtual int32 GetPlayerLevel() override;
	//~ End Combat Interface

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
private:
};
