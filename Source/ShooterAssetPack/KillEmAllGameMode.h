// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameMode.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AKillEmAllGameMode : public AShooterGameMode
{
	GENERATED_BODY()

	virtual void PawnKilled(APawn* pawnKilled) override;

	void EndGame(bool bisPlayerWinner);
	
};
