//

// TrueAStar.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 21 16:44:05 2016 stephane galibert
// Last update Wed Jun  1 17:00:00 2016 jeremy Care
//

#ifndef _TRUEASTAR_HPP_
#define _TRUEASTAR_HPP_

#include <irrlicht.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>

#include "Map.hpp"
#include "IAStar.hpp"

namespace bbman {
class TrueAStar : public IAStar
{
public:

  TrueAStar(void);
  ~TrueAStar(void);
  void                         addBlockType(bbman::ItemID const& blocktype);
  void                         compute(const Map<bbman::Cell>& map, irr::core::vector3d<irr::s32>const& p1,
                                       irr::core::vector3d<irr::s32>const& p2);
  irr::core::vector3d<irr::s32>getNextResult(void);
  void                         reset(void);
  bool                         isBlock(bbman::ItemID const& id);
  size_t                       getSize(void);

private:

  struct Node
  {
    Node(void);
    Node(irr::core::vector3d<irr::s32>const& pos);
    Node                       & operator=(Node const& other);
    irr::core::vector3d<irr::s32>parent;
    irr::core::vector3d<irr::s32>pos;
    float                        g;
    float                        h;
    float                        f;
  };
  void  addAdjCase(const bbman::Map<bbman::Cell>& map, Node const& p,
                   irr::core::vector3d<irr::s32>const& obj);
  float getDistance(irr::core::vector3d<irr::s32>const& p1,
                    irr::core::vector3d<irr::s32>const& p2) const;
  bool  findInList(Node const& p, std::vector<Node>& list) const;
  void  addInList(Node node, std::vector<Node>& list);
  void  addInCloseList(Node const& p);
  Node& getNode(irr::core::vector3d<irr::s32>const& p, std::vector<Node>& list) const;
  Node  getBestNode(std::vector<Node>& list) const;
  void  retrievePath(irr::core::vector3d<irr::s32>const& begin);
  std::vector<Node> _listClose;
  std::vector<Node> _listOpen;
  std::vector<bbman::ItemID> _blockType;
  Node _end;
  std::list<irr::core::vector3d<irr::s32> >_path;
  irr::core::vector3d<irr::s32> _begin;
};
}

#endif /* !_TRUEASTAR_HPP_ */
