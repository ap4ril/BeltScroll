// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "FloorTile.generated.h"

class UArrowComponent;
class UStaticMeshComponent;
class USceneComponent;
class UBoxComponent;

UCLASS()
class BELTSCROLL_API AFloorTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* FloorMesh;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* AttachPoint;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* CenterLane;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* RightLane;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* LeftLane;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* FloorTriggerBox;

	AFloorTile();

	FORCEINLINE const FTransform& GetAttachTransform() const
	{
		return AttachPoint->GetComponentTransform();
	}

protected:
	UPROPERTY(VisibleInstanceOnly)
		class ABeltScrollGameModeBase* RungameMode;

	UPROPERTY()
		FTimerHandle DestroyHandle;

	UFUNCTION()
		void OnTriggerBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void DestroyFloorTile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
