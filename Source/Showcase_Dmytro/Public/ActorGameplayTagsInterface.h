// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ActorGameplayTagsInterface.generated.h"

UINTERFACE(BlueprintType)
class SHOWCASE_DMYTRO_API UActorGameplayTagsInterface : public UInterface
{
	GENERATED_BODY()
};

class SHOWCASE_DMYTRO_API IActorGameplayTagsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Gameplay Tags")
	void AddGameplayTag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Gameplay Tags")
	void RemoveGameplayTag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Gameplay Tags")
	FGameplayTagContainer GetGameplayTagContainer() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Gameplay Tags")
	bool HasGameplayTag(FGameplayTag Tag) const;
};
