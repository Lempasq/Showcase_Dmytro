// Showcase_Dmytro 2026

#pragma once

#include "CoreMinimal.h"
#include "FootballData.generated.h"

// Enumeration for Teams
UENUM(BlueprintType)
enum class ETeams : uint8
{        
	None,
	TeamBlue,    
	TeamRed     
};

// Enumeration for Ball States
UENUM(BlueprintType)
enum class EBallStates : uint8
{
	Free,
	GrabbedByPlayer,
	GrabbedByGoalKeeper
};


// Enumeration for Match States Handled in GameMode
UENUM(BlueprintType)
enum class EMatchStates : uint8
{
	InLobby,
	OnGoingMatch,
	Celebrating,
	Finished
};


// Structure for Scoreboard Data
USTRUCT(BlueprintType)
struct FScoreboardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TeamBlueScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TeamRedScore = 0;

};