// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode :: PawnKilled(APawn * pawnKilled)
{
	Super::PawnKilled(pawnKilled);

	UE_LOG(LogTemp, Display, TEXT("Pawn is Dead"));
}