/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkLungWallFeatureGenerator.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkLungWallFeatureGenerator_txx
#define __itkLungWallFeatureGenerator_txx

#include "itkLungWallFeatureGenerator.h"


namespace itk
{

/**
 * Constructor
 */
template <unsigned int NDimension>
LungWallFeatureGenerator<NDimension>
::LungWallFeatureGenerator()
{
  this->SetNumberOfRequiredInputs( 1 );
  this->SetNumberOfRequiredOutputs( 1 );

  this->m_ThresholdFilter = ThresholdFilterType::New();
  this->m_VotingHoleFillingFilter = VotingHoleFillingFilterType::New();

  typename OutputImageSpatialObjectType::Pointer outputObject = OutputImageSpatialObjectType::New();

  this->ProcessObject::SetNthOutput( 0, outputObject.GetPointer() );

  this->m_LungThreshold = -400.0;
}


/*
 * Destructor
 */
template <unsigned int NDimension>
LungWallFeatureGenerator<NDimension>
::~LungWallFeatureGenerator()
{
}

template <unsigned int NDimension>
void
LungWallFeatureGenerator<NDimension>
::SetInput( const SpatialObjectType * spatialObject )
{
  // Process object is not const-correct so the const casting is required.
  this->SetNthInput(0, const_cast<SpatialObjectType *>( spatialObject ));
}

template <unsigned int NDimension>
const typename LungWallFeatureGenerator<NDimension>::SpatialObjectType *
LungWallFeatureGenerator<NDimension>
::GetFeature() const
{
  if (this->GetNumberOfOutputs() < 1)
    {
    return 0;
    }

  return static_cast<const SpatialObjectType*>(this->ProcessObject::GetOutput(0));

}


/*
 * PrintSelf
 */
template <unsigned int NDimension>
void
LungWallFeatureGenerator<NDimension>
::PrintSelf(std::ostream& os, Indent indent) const
{
  Superclass::PrintSelf( os, indent );
  os << indent << "Lung threshold " << this->m_ThresholdFilter << std::endl;
}


/*
 * Generate Data
 */
template <unsigned int NDimension>
void
LungWallFeatureGenerator<NDimension>
::GenerateData()
{
  typename InputImageSpatialObjectType::ConstPointer inputObject =
    dynamic_cast<const InputImageSpatialObjectType * >( this->ProcessObject::GetInput(0) );

  if( !inputObject )
    {
    itkExceptionMacro("Missing input spatial object");
    }

  const InputImageType * inputImage = inputObject->GetImage();

  if( !inputImage )
    {
    itkExceptionMacro("Missing input image");
    }

  this->m_ThresholdFilter->SetInput( inputImage );
  this->m_VotingHoleFillingFilter->SetInput( this->m_ThresholdFilter->GetOutput() );

  this->m_ThresholdFilter->SetLowerThreshold( this->m_LungThreshold );
  this->m_ThresholdFilter->SetUpperThreshold( 1000.0 );

  this->m_ThresholdFilter->SetInsideValue( 0.0 );
  this->m_ThresholdFilter->SetOutsideValue( 1.0 );

  typename InternalImageType::SizeType  ballManhattanRadius;

  ballManhattanRadius.Fill( 2 );

  this->m_VotingHoleFillingFilter->SetRadius( ballManhattanRadius );
  this->m_VotingHoleFillingFilter->SetBackgroundValue( 0.0 );
  this->m_VotingHoleFillingFilter->SetForegroundValue( 1.0 );
  this->m_VotingHoleFillingFilter->SetMajorityThreshold( 1 );
  this->m_VotingHoleFillingFilter->SetMaximumNumberOfIterations( 100 );

  this->m_VotingHoleFillingFilter->Update();

  typename OutputImageType::Pointer outputImage = this->m_VotingHoleFillingFilter->GetOutput();

  outputImage->DisconnectPipeline();

  typedef ImageSpatialObject< Dimension, OutputPixelType > OutputImageSpatialObjectType;

  OutputImageSpatialObjectType * outputObject =
    dynamic_cast< OutputImageSpatialObjectType * >(this->ProcessObject::GetOutput(0));

  outputObject->SetImage( outputImage );
}

} // end namespace itk

#endif