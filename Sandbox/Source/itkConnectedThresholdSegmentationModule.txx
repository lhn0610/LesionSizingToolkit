/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkConnectedThresholdSegmentationModule.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkConnectedThresholdSegmentationModule_txx
#define __itkConnectedThresholdSegmentationModule_txx

#include "itkConnectedThresholdSegmentationModule.h"


namespace itk
{

/**
 * Constructor
 */
template <unsigned int NDimension>
ConnectedThresholdSegmentationModule<NDimension>
::ConnectedThresholdSegmentationModule()
{
  this->SetNumberOfRequiredInputs( 2 );
  this->SetNumberOfRequiredOutputs( 1 );
}


/**
 * Destructor
 */
template <unsigned int NDimension>
ConnectedThresholdSegmentationModule<NDimension>
::~ConnectedThresholdSegmentationModule()
{
}


/**
 * PrintSelf
 */
template <unsigned int NDimension>
void
ConnectedThresholdSegmentationModule<NDimension>
::PrintSelf(std::ostream& os, Indent indent) const
{
  Superclass::PrintSelf( os, indent );
}


/**
 * Generate Data
 */
template <unsigned int NDimension>
void
ConnectedThresholdSegmentationModule<NDimension>
::GenerateData()
{

}

} // end namespace itk

#endif
