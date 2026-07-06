// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorGameplayTagsInterface.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class SHOWCASE_DMYTRO_API ABaseCharacter : public ACharacter, public IActorGameplayTagsInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	virtual void AddGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual void RemoveGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual FGameplayTagContainer GetGameplayTagContainer_Implementation() const override;
	virtual bool HasGameplayTag_Implementation(FGameplayTag Tag) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_OwnedGameplayTags, Category = "Gameplay Tags")
	FGameplayTagContainer OwnedGameplayTags;

	UFUNCTION()
	void OnRep_OwnedGameplayTags(const FGameplayTagContainer& PreviousGameplayTags);

	UFUNCTION(BlueprintImplementableEvent, Category = "Gameplay Tags")
	void OnOwnedGameplayTagsChanged(FGameplayTagContainer PreviousGameplayTags, FGameplayTagContainer NewGameplayTags);

	void HandleOwnedGameplayTagsChanged(const FGameplayTagContainer& PreviousGameplayTags);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
