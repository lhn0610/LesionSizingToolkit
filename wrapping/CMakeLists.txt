itk_wrap_module(LesionSizingToolkit)

set(WRAPPER_SUBMODULE_ORDER
   itkBinaryThresholdFeatureGenerator
   itkCannyEdgeDetectionRecursiveGaussianImageFilter
   itkCannyEdgesDistanceAdvectionFieldFeatureGenerator
   itkCannyEdgesDistanceFeatureGenerator
   itkCannyEdgesFeatureGenerator
   itkConfidenceConnectedSegmentationModule
   itkConnectedreoldSegmentationModule
   itkDescoteauxeetnessFeatureGenerator
   itkDescoteauxeetnessImageFilter
   itkFastMaringAndGeodesicActiveContourLevelSetSegmentationModule
   itkFastMaringAndapeDetectionLevelSetSegmentationModule
   itkFastMaringSegmentationModule
   itkFeatureAggregator
   itkFeatureGenerator
   itkFrangiTubularnessFeatureGenerator
   itkFrangiTubularnessImageFilter
   itkGeodesicActiveContourLevelSetSegmentationModule
   itkGradientMagnitudeSigmoidFeatureGenerator
   itkGrayscaleImageSegmentationVolumeEstimator
   itkIsotropicResampler
   itkIsotropicResamplerImageFilter
   itkLandmarksReader
   itkLesionSegmentationImageFilter8
   itkLesionSegmentationMeod
   itkLocalStructureImageFilter
   itkLungWallFeatureGenerator
   itkMaximumFeatureAggregator
   itkMinimumFeatureAggregator
   itkMorologicalOpenningFeatureGenerator
   itkRegionCompetitionImageFilter
   itkRegionGrowingSegmentationModule
   itkSatoLocalStructureFeatureGenerator
   itkSatoVesselnessFeatureGenerator
   itkSatoVesselnessSigmoidFeatureGenerator
   itkSegmentationModule
   itkSegmentationVolumeEstimator
   itkapeDetectionLevelSetSegmentationModule
   itkSigmoidFeatureGenerator
   itkSingleaseLevelSetSegmentationModule
   itkVesselEancingDiffusion3DImageFilter
   itkVotingBinaroleFillFloodingImageFilter
   itkWeitedSumFeatureAggregator)

itk_auto_load_submodules()
itk_end_wrap_module()
