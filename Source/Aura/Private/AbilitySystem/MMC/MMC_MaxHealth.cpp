// Copyright New Dawn Group LTD 2023. All Rights Reserved.


#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/AuraCombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VigorDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Vigor = 0.f;
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvaluationParameters, Vigor);
	Vigor = FMath::Max<float>(Vigor, 0.f);

	IAuraCombatInterface* AuraCombatInterface = Cast<IAuraCombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = AuraCombatInterface->GetPlayerLevel();

	return 80.f + 2.5f * Vigor + 10.f * PlayerLevel;	
}
