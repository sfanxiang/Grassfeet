// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "array.h"
#include "Components/StaticMeshComponent.h"
#include "generate_graph.generated.h"

UENUM(BlueprintType)
enum class PointFillStatus : uint8 {
	Empty,
	Path,
	Grass
};
USTRUCT(Blueprintable)
struct FPoint {

	GENERATED_BODY()
	PointFillStatus fill_status;
	bool has_cow;
	TArray<PxU32> next;
	FPoint() : fill_status(PointFillStatus::Empty), has_cow() {}
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT4_API Ugenerate_graph : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	// Sets default values for this component's properties
	Ugenerate_graph();
	UFUNCTION(BlueprintPure,
		meta = (DisplayName = "Makes a Graph",
			CompactNodeTitle = "make_graph",
			Keywords = "graph make grassfeet"),
		Category = Game)
		static TArray<FPoint> make_graph(UStaticMeshComponent *mesh);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
