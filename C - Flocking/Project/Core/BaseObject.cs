using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using Microsoft.DirectX;

namespace FullSailAFI.SteeringBehaviors.Core
{
    public class BaseObject
    {
        #region Properties

        public Vector3 Position { get; set; }
        public float CollisionRadius { get; set; }
         
        #endregion

        #region Constructors
        public BaseObject()
        {
            Position = Vector3.Empty;
            CollisionRadius = 0;
        }
        #endregion
    }
}
