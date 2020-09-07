namespace PatioSim.Data.Models
{
    using System;
    using System.ComponentModel.DataAnnotations;
    public class BaseEntity
    {
        [Required]
        public Guid ID { get; set; } = Guid.NewGuid();
        public string Name { get; set; }
        public string Description { get; set; }
        private bool _isDisabled;
        public DateTime CreatedOn { get; set; }
        public DateTime ModifiedOn { get; set; }
        public DateTime? DisabledOn { get; set; }
        public Guid CreatedBy { get; set; }
        public Guid ModifiedBy { get; set; }
        public Guid OwnerId { get; set; }
        public bool IsDisabled
        {
            get { return _isDisabled; }
            set
            {
                _isDisabled = value;
                DisabledOn = value
                    ? (DateTime?)DateTime.UtcNow
                    : null;
            }
        }
    }
}