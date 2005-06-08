/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    ComplexImageReadWrite.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

//  Software Guide : BeginLatex
//
//  This example illustrates how to read and write an image of pixel type
//  \code{std::complex}. The complex type is defined as an integral part of the
//  C++ language. The characteristics of the type are specified in the C++
//  standard document in Chapter 26 "Numerics Library", page 565, in particular
//  in section 26.2~\cite{CPPStandard1998}.
//
//  We start by including the headers of the complex class, the image, and the
//  reader and writer classes.
//
//  \index{itk::ImageFileRead!Complex images}
//  \index{itk::ImageFileWrite!Complex images}
//  \index{Complex images!Instantiation}
//  \index{Complex images!Reading}
//  \index{Complex images!Writing}
//
//  Software Guide : EndLatex 


// Software Guide : BeginCodeSnippet
#include <complex>
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
// Software Guide : EndCodeSnippet


int main( int argc, char * argv [] )
{

  // Verify the number of parameters in the command line
  if( argc < 3 )
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " inputImageFile  outputImageFile " << std::endl;
    return EXIT_FAILURE;
    }

// Software Guide : BeginLatex
//
// The image dimension and pixel type must be declared. In this case we use the
// \code{std::complex<>} as the pixel type. Using the dimension and pixel type
// we proceed to instantiate the image type.
//
// Software Guide : EndLatex 


// Software Guide : BeginCodeSnippet
  const unsigned int Dimension = 2;

  typedef std::complex< float >    PixelType;
  typedef itk::Image< PixelType, Dimension > ImageType;
// Software Guide : EndCodeSnippet

  


// Software Guide : BeginLatex
//
// The image file reader and writer types are instantiated using the image
// type. We can then create objects for both of them.
//
// Software Guide : EndLatex 
 
// Software Guide : BeginCodeSnippet
  typedef itk::ImageFileReader< ImageType > ReaderType;
  typedef itk::ImageFileWriter< ImageType > WriterType;

  ReaderType::Pointer reader = ReaderType::New();
  WriterType::Pointer writer = WriterType::New();
// Software Guide : EndCodeSnippet


  

// Software Guide : BeginLatex
//
// Filenames should be provided for both the reader and the writer. In this
// particular example we take those filenames from the command line arguments.
//
// Software Guide : EndLatex 

// Software Guide : BeginCodeSnippet
  reader->SetFileName( argv[1] );
  writer->SetFileName( argv[2] );
// Software Guide : EndCodeSnippet




// Software Guide : BeginLatex
//
// Here we simply connect the output of the reader as input to the writer.
// This simple program could be used for converting complex images from one
// fileformat to another.
//
// Software Guide : EndLatex 

// Software Guide : BeginCodeSnippet
  writer->SetInput( reader->GetOutput() );
// Software Guide : EndCodeSnippet




// Software Guide : BeginLatex
//
// The execution of this short pipeline is triggered by invoking the Update()
// method of the writer. This invokation must be placed inside a try/catch
// block since its execution may result in exeptions being thrown.
//
// Software Guide : EndLatex 

// Software Guide : BeginCodeSnippet
  try
    {
    writer->Update();
    }
  catch( itk::ExceptionObject & err ) 
    { 
    std::cerr << "ExceptionObject caught !" << std::endl; 
    std::cerr << err << std::endl; 
    return EXIT_FAILURE;
    } 
// Software Guide : EndCodeSnippet



// Software Guide : BeginLatex
//
// For a more interesting use of this code, you may want to add a filter in
// between the reader and the writer and perform any complex image to complex
// image operation. A practical application of this code is presented in
// section~\ref{sec:FrequencyDomain} in the context of Fourier analysis.
//
// Software Guide : EndLatex 


  return EXIT_SUCCESS;
}
