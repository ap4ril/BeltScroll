// Copyright Epic Games, Inc. All Rights Reserved.


#include "BeltScrollGameModeBase.h"
#include "FloorTile.h"


void ABeltScrollGameModeBase::BeginPlay()
{
	CreateInitialFloorTiles();
}

void ABeltScrollGameModeBase::CreateInitialFloorTiles()
{
	AFloorTile* Tile = AddFloorTile();

	if (Tile)
	{
		LaneSwitchValues.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->CenterLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->RightLane->GetComponentLocation().Y);
	}

	for (float Val : LaneSwitchValues)
	{
		UE_LOG(LogTemp, Warning, TEXT("LANE VALUE: %f"), Val);
	}

	for (int i = 0; i < NumInitialFloorTiles; i++)
	{
		AddFloorTile();
	}
}

AFloorTile* ABeltScrollGameModeBase::AddFloorTile()
{
	UWorld* World = GetWorld();
	if(World)
	{
		AFloorTile* Tile = GetWorld()->SpawnActor<AFloorTile>(FloorTileClass, NextSpawnPoint);
		if (Tile)
		{
			NextSpawnPoint = Tile->GetAttachTransform();
		}
		return Tile;
	}
	return nullptr;
}
