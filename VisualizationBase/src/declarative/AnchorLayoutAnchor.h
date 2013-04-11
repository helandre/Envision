/***********************************************************************************************************************
 **
 ** Copyright (c) 2011, 2013 ETH Zurich
 ** All rights reserved.
 **
 ** Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 ** following conditions are met:
 **
 **    * Redistributions of source code must retain the above copyright notice, this list of conditions and the
 **      following disclaimer.
 **    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 **      following disclaimer in the documentation and/or other materials provided with the distribution.
 **    * Neither the name of the ETH Zurich nor the names of its contributors may be used to endorse or promote products
 **      derived from this software without specific prior written permission.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 ** INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 ** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 ** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 ** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **
 **********************************************************************************************************************/

#pragma once

namespace Visualization {

class Item;
class Element;

class AnchorLayoutAnchor {
	public:
		enum class Orientation : int {Auto, Horizontal, Vertical};
		AnchorLayoutAnchor(float relativePlaceEdgePosition, Element* placeElement, int offset,
				float relativeFixedEdgePosition, Element* fixedElement);
		virtual ~AnchorLayoutAnchor();
		int execute(Item* item, Orientation orientation);
		Element* placeElement() const;
		Element* fixedElement() const;
		bool dependsOn(AnchorLayoutAnchor* other, QList<AnchorLayoutAnchor*>& allConstraints);
		float relativePlaceEdgePosition() const;
		float relativeFixedEdgePosition() const;
		int offset() const;

	private:
		float relativePlaceEdgePosition_{};
		Element* placeElement_{};
		int offset_{};
		float relativeFixedEdgePosition_{};
		Element* fixedElement_{};
};

inline Element* AnchorLayoutAnchor::placeElement() const
{
	return placeElement_;
}
inline Element* AnchorLayoutAnchor::fixedElement() const
{
	return fixedElement_;
}
inline float AnchorLayoutAnchor::relativePlaceEdgePosition() const
{
	return relativePlaceEdgePosition_;
}
inline float AnchorLayoutAnchor::relativeFixedEdgePosition() const
{
	return relativeFixedEdgePosition_;
}
inline int AnchorLayoutAnchor::offset() const
{
	return offset_;
}

} /* namespace Visualization */