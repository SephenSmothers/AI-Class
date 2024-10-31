using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using FullSailAFI.SteeringBehaviors.Core;

namespace FullSailAFI.SteeringBehaviors.StudentAI
{
    public class Flock
    {
        public float AlignmentStrength { get; set; }
        public float CohesionStrength { get; set; }
        public float SeparationStrength { get; set; }
        public List<MovingObject> Boids { get; protected set; }
        public Vector3 AveragePosition { get; set; }
        protected Vector3 AverageForward { get; set; }
        public float FlockRadius { get; set; }

        #region Constructors
        public Flock()
        {
        }
        #endregion

        #region TODO Suggested helper methods

        private void CalculateAverages()
        {

            Vector3 averageVelocity = new Vector3(0, 0, 0);
            Vector3 averagePosition = new Vector3(0, 0, 0);

            AverageForward = Vector3.Empty;
            AveragePosition = Vector3.Empty;

            foreach (MovingObject otherBoid in Boids)
            {
                averageVelocity += otherBoid.Velocity;
                averagePosition += otherBoid.Position;
            }

            averageVelocity /= (Boids.Count());
            averagePosition /= (Boids.Count());

            AverageForward = averageVelocity;
            AveragePosition = averagePosition;
        }

        private Vector3 CalculateAlignmentAcceleration(MovingObject boid)
        {
            Vector3 alignment = AverageForward / boid.MaxSpeed;

            if(alignment.Length > 1)
            {
                alignment.Normalize();
            }

            return (alignment * AlignmentStrength);
        }

        private Vector3 CalculateCohesionAcceleration(MovingObject boid)
        {
            Vector3 cohesion = AveragePosition - boid.Position;

            float distance = cohesion.Length;

            cohesion.Normalize();

            if (distance < FlockRadius)
            {
                cohesion *= (distance / FlockRadius);
            }

            if (cohesion.Length > 1.0f)
            {
                cohesion.Normalize();
            }

            return (cohesion * CohesionStrength);
        }

        private Vector3 CalculateSeparationAcceleration(MovingObject boid)
        {
            Vector3 sum = Vector3.Empty;

            foreach (MovingObject otherBoid in Boids)
            {
                Vector3 vec = boid.Position - otherBoid.Position;
                float distance = vec.Length;
                float safeDistance = boid.SafeRadius + otherBoid.SafeRadius;

                if (distance < safeDistance)
                {
                    vec.Normalize();
                    vec *= (safeDistance - distance) / safeDistance;
                    sum += vec;
                }
            }

            if(sum.Length > 1.0f)
            {
                sum.Normalize();
            }

            return (sum * SeparationStrength);
        }

        #endregion

        #region TODO

        public virtual void Update(float deltaTime)
        {
            CalculateAverages();

            Vector3 sum = new Vector3(0,0,0);

            for (int i = 0; i < Boids.Count(); i++) 
            {
                sum = CalculateAlignmentAcceleration(Boids[i]);
                sum += CalculateCohesionAcceleration(Boids[i]);
                sum += CalculateSeparationAcceleration(Boids[i]);
                sum *= (Boids[i].MaxSpeed * deltaTime);

                Boids[i].Velocity += sum;

                if (Boids[i].Velocity.Length > Boids[i].MaxSpeed)
                {
                    Boids[i].Velocity.Normalize();
                    Boids[i].Velocity *= Boids[i].MaxSpeed;
                }

                Boids[i].Update(deltaTime);
            }

            return;
        }
        #endregion
    }
}
