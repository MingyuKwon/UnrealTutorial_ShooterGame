// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "ShooterAI.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillEmAllGameMode :: PawnKilled(APawn * pawnKilled)
{
	Super::PawnKilled(pawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(pawnKilled->GetController());

	if (PlayerController)
	{
		EndGame(false);
	}
	else
	{
		for (AShooterAI* controller : TActorRange<AShooterAI>(GetWorld()))
		{
			if (!controller->isDead())
			{
				return;
			}
		}

		EndGame(true);
	}

}

void AKillEmAllGameMode::EndGame(bool bisPlayerWinner)
{
	for (AController* controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = controller->IsPlayerController() == bisPlayerWinner;
		controller->GameHasEnded(controller->GetPawn(), bIsWinner);
	}
}
