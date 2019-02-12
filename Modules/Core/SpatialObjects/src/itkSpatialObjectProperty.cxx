/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkSpatialObjectProperty_cxx
#define itkSpatialObjectProperty_cxx

#include "itkSpatialObjectProperty.h"

namespace itk
{
SpatialObjectProperty
::SpatialObjectProperty()
{
  m_MTime = 0;

  m_Color.SetRed(1);
  m_Color.SetGreen(1);
  m_Color.SetBlue(1);
  m_Color.SetAlpha(1);

  m_Name = "";

  m_ScalarDictionary.clear();
  m_StringDictionary.clear();
}

SpatialObjectProperty
::~SpatialObjectProperty() = default;

void
SpatialObjectProperty
::SetColor(double r, double g, double b)
{
  m_Color.SetRed(r);
  m_Color.SetGreen(g);
  m_Color.SetBlue(b);
  this->Modified();
}

void
SpatialObjectProperty
::SetRed(double r)
{
  m_Color.SetRed(r);
  this->Modified();
}

double
SpatialObjectProperty
::GetRed() const
{
  return m_Color.GetRed();
}

void
SpatialObjectProperty
::SetGreen(double g)
{
  m_Color.SetGreen(g);
  this->Modified();
}

double
SpatialObjectProperty
::GetGreen() const
{
  return m_Color.GetGreen();
}

void
SpatialObjectProperty
::SetBlue(double b)
{
  m_Color.SetBlue(b);
  this->Modified();
}

double
SpatialObjectProperty
::GetBlue() const
{
  return m_Color.GetBlue();
}

void
SpatialObjectProperty
::SetAlpha(double a)
{
  m_Color.SetAlpha(a);
  this->Modified();
}

double
SpatialObjectProperty
::GetAlpha() const
{
  return m_Color.GetAlpha();
}

void
SpatialObjectProperty
::SetTagScalarValue( const std::string & tag, double value )
{
  m_ScalarDictionary[ tag ] = value;
}

void
SpatialObjectProperty
::SetTagStringValue( const std::string & tag, const std::string & value )
{
  m_StringDictionary[ tag ] = value;
}

double
SpatialObjectProperty
::GetTagScalarValue( const std::string & tag ) const
{
  return m_ScalarDictionary.find( tag )->second;
}

std::map< std::string, double > &
SpatialObjectProperty
::GetTagScalarDictionary()
{
  return m_ScalarDictionary;
}

const std::map< std::string, double > &
SpatialObjectProperty
::GetTagScalarDictionary() const
{
  return m_ScalarDictionary;
}

std::map< std::string, std::string > &
SpatialObjectProperty
::GetTagStringDictionary()
{
  return m_StringDictionary;
}

const std::map< std::string, std::string > &
SpatialObjectProperty
::GetTagStringDictionary() const
{
  return m_StringDictionary;
}

void
SpatialObjectProperty
::SetTagScalarDictionary( const std::map< std::string, double > & dict )
{
  m_ScalarDictionary = dict;
}

void
SpatialObjectProperty
::SetTagStringDictionary(const std::map< std::string, std::string > & dict )
{
  m_StringDictionary = dict;
}

void
SpatialObjectProperty
::DeepCopy( const SpatialObjectProperty * rhs )
{
  this->SetName( rhs->GetName() );
  this->SetColor( rhs->GetColor() );

  this->SetTagScalarDictionary( rhs->GetTagScalarDictionary() );
  this->SetTagStringDictionary( rhs->GetTagStringDictionary() );
}

void
SpatialObjectProperty
::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);
  os << indent << "Name: " << m_Name << std::endl;
  os << indent << "RGBA: " << m_Color.GetRed() << " " << m_Color.GetGreen()
    << " " << m_Color.GetBlue() << " " << m_Color.GetAlpha() << std::endl;
  os << indent << "ScalarDictionary size: " << m_ScalarDictionary.size()
    << std::endl;
  os << indent << "StringDictionary size: " << m_StringDictionary.size()
    << std::endl;
  os << indent << "MTime: " << m_MTime << std::endl;
}
} // end of namespace itk

#endif // __SpatialObjectProperty_hxx