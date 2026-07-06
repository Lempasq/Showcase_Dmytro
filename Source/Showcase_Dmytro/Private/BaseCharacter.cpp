// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ABaseCharacter, OwnedGameplayTags, COND_None, REPNOTIFY_Always);
}

void ABaseCharacter::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = OwnedGameplayTags;
}

void ABaseCharacter::AddGameplayTag_Implementation(FGameplayTag Tag)
{
	if (Tag.IsValid() && !OwnedGameplayTags.HasTagExact(Tag))
	{
		const FGameplayTagContainer PreviousGameplayTags = OwnedGameplayTags;
		OwnedGameplayTags.AddTag(Tag);

		if (HasAuthority())
		{
			HandleOwnedGameplayTagsChanged(PreviousGameplayTags);
		}
	}
}

void ABaseCharacter::RemoveGameplayTag_Implementation(FGameplayTag Tag)
{
	if (OwnedGameplayTags.HasTagExact(Tag))
	{
		const FGameplayTagContainer PreviousGameplayTags = OwnedGameplayTags;
		OwnedGameplayTags.RemoveTag(Tag);

		if (HasAuthority())
		{
			HandleOwnedGameplayTagsChanged(PreviousGameplayTags);
		}
	}
}

FGameplayTagContainer ABaseCharacter::GetGameplayTagContainer_Implementation() const
{
	return OwnedGameplayTags;
}

bool ABaseCharacter::HasGameplayTag_Implementation(FGameplayTag Tag) const
{
	return OwnedGameplayTags.HasTag(Tag);
}

void ABaseCharacter::OnRep_OwnedGameplayTags(const FGameplayTagContainer& PreviousGameplayTags)
{
	HandleOwnedGameplayTagsChanged(PreviousGameplayTags);
}

void ABaseCharacter::HandleOwnedGameplayTagsChanged(const FGameplayTagContainer& PreviousGameplayTags)
{
	OnOwnedGameplayTagsChanged(PreviousGameplayTags, OwnedGameplayTags);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
