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
	
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
};
