// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode :: PawnKilled(APawn * pawnKilled)
{
	Super::PawnKilled(pawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(pawnKilled->GetController());

	if (PlayerController)
	{
		PlayerController->GameHasEnded();
	}

}